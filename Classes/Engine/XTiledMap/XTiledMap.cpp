/****************************************************************************
Copyright (c) 2009-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "XTiledMap.h"
#include "XTileLayer.h"
#include "base/ccUTF8.h"



XTiledMap * XTiledMap::create(const std::string& tmxFile)
{
    XTiledMap *ret = new (std::nothrow) XTiledMap();
    if (ret->initWithTMXFile(tmxFile))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

XTiledMap* XTiledMap::createWithXML(const std::string& tmxString, const std::string& resourcePath)
{
    XTiledMap *ret = new (std::nothrow) XTiledMap();
    if (ret->initWithXML(tmxString, resourcePath))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool XTiledMap::initWithTMXFile(const std::string& tmxFile)
{
    CCASSERT(tmxFile.size()>0, "FastXTiledMap: tmx file should not be empty");
    
    setContentSize(Size::ZERO);

    XTileMapInfo *mapInfo = XTileMapInfo::create(tmxFile);

    if (! mapInfo)
    {
        return false;
    }
    CCASSERT( !mapInfo->getTilesets().empty(), "FastXTiledMap: Map not found. Please check the filename.");
    buildWithMapInfo(mapInfo);

    return true;
}

bool XTiledMap::initWithXML(const std::string& tmxString, const std::string& resourcePath)
{
    setContentSize(Size::ZERO);

    XTileMapInfo *mapInfo = XTileMapInfo::createWithXML(tmxString, resourcePath);

    CCASSERT( !mapInfo->getTilesets().empty(), "FastXTiledMap: Map not found. Please check the filename.");
    buildWithMapInfo(mapInfo);

    return true;
}

XTiledMap::XTiledMap()
    :_mapSize(Size::ZERO)
    ,_tileSize(Size::ZERO)        
{
}

XTiledMap::~XTiledMap()
{
}

// private
XTileLayer * XTiledMap::parseLayer(XTileLayerInfo *layerInfo, XTileMapInfo *mapInfo)
{
    XTilesetInfo *tileset = tilesetForLayer(layerInfo, mapInfo);
    if (tileset == nullptr)
        return nullptr;
    
    XTileLayer *layer = XTileLayer::create(tileset, layerInfo, mapInfo);

    // tell the layerinfo to release the ownership of the tiles map.
    layerInfo->_ownTiles = false;
    layer->setupTiles();

    return layer;
}

XTilesetInfo * XTiledMap::tilesetForLayer(XTileLayerInfo *layerInfo, XTileMapInfo *mapInfo)
{
    Size size = layerInfo->_layerSize;
    auto& tilesets = mapInfo->getTilesets();

    for (auto iter = tilesets.crbegin(), iterCrend = tilesets.crend(); iter != iterCrend; ++iter)
    {
        XTilesetInfo* tilesetInfo = *iter;
        if (tilesetInfo)
        {
            for( int y=0; y < size.height; y++ )
            {
                for( int x=0; x < size.width; x++ )
                {
                    uint32_t pos = static_cast<uint32_t>(x + size.width * y);
                    uint32_t gid = layerInfo->_tiles[ pos ];
                    
                    // gid are stored in little endian.
                    // if host is big endian, then swap
                    //if( o == CFByteOrderBigEndian )
                    //    gid = CFSwapInt32( gid );
                    /* We support little endian.*/
                    
                    // FIXME: gid == 0 --> empty tile
                    if( gid != 0 )
                    {
                        // Optimization: quick return
                        // if the layer is invalid (more than 1 tileset per layer) an CCAssert will be thrown later
                        if( (gid & kXTileFlippedMask)
                            >= static_cast<uint32_t>(tilesetInfo->_firstGid))
                        {
                            return tilesetInfo;
                        }
                    }
                }
            }
        }
    }

    // If all the tiles are 0, return empty tileset
    CCLOG("cocos2d: Warning: TMX Layer '%s' has no tiles", layerInfo->_name.c_str());
    return nullptr;
}

void XTiledMap::buildWithMapInfo(XTileMapInfo* mapInfo)
{
    _mapSize = mapInfo->getMapSize();
    _tileSize = mapInfo->getTileSize();
    _mapOrientation = mapInfo->getOrientation();

    _objectGroups = mapInfo->getObjectGroups();

    _properties = mapInfo->getProperties();

    _tileProperties = mapInfo->getTileProperties();

    int idx=0;

    auto& layers = mapInfo->getLayers();
    for(const auto &layerInfo : layers) {
        if (layerInfo->_visible)
        {
            XTileLayer *child = parseLayer(layerInfo, mapInfo);
            if (child == nullptr) {
                idx++;
                continue;
            }
            addChild(child, idx, idx);
            
            // update content size with the max size
            const Size& childSize = child->getContentSize();
            Size currentSize = this->getContentSize();
            currentSize.width = std::max( currentSize.width, childSize.width );
            currentSize.height = std::max( currentSize.height, childSize.height );
            this->setContentSize(currentSize);
            
            idx++;
        }
    }
}

// public
XTileLayer * XTiledMap::getLayer(const std::string& layerName) const
{
    CCASSERT(layerName.size() > 0, "Invalid layer name!");
    
    for (auto& child : _children)
    {
        XTileLayer* layer = dynamic_cast<XTileLayer*>(child);
        if(layer)
        {
            if(layerName.compare( layer->getLayerName()) == 0)
            {
                return layer;
            }
        }
    }

    // layer not found
    return nullptr;
}

XTileObjectGroup * XTiledMap::getObjectGroup(const std::string& groupName) const
{
    CCASSERT(groupName.size() > 0, "Invalid group name!");

    if (_objectGroups.size()>0)
    {
        for (const auto& objectGroup : _objectGroups)
        {
            if (objectGroup && objectGroup->getGroupName() == groupName)
            {
                return objectGroup;
            }
        }
    }

    // objectGroup not found
    return nullptr;
}

Value XTiledMap::getProperty(const std::string& propertyName) const
{
    auto propsItr = _properties.find(propertyName);
    if (propsItr != _properties.end())
        return propsItr->second;
    
    return Value();
}

Value XTiledMap::getPropertiesForGID(int GID) const
{
    auto propsItr = _tileProperties.find(GID);
    if (propsItr != _tileProperties.end())
        return propsItr->second;
    
    return Value();
}

std::string XTiledMap::getDescription() const
{
    return StringUtils::format("<FastXTiledMap | Tag = %d, Layers = %d", _tag, static_cast<int>(_children.size()));
}


