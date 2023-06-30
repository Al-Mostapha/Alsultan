/****************************************************************************
Copyright (c) 2011      Максим Аксенов 
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

#include "XTileXMLParser.h"
#include <unordered_map>
#include <sstream>
#include "XTiledMap.h"
#include "base/ZipUtils.h"
#include "base/base64.h"
#include "base/CCDirector.h"
#include "platform/CCFileUtils.h"

using namespace std;
USING_NS_CC;
// implementation XTileLayerInfo
XTileLayerInfo::XTileLayerInfo()
: _name("")
, _tiles(nullptr)
, _ownTiles(true)
{
}

XTileLayerInfo::~XTileLayerInfo()
{
    CCLOGINFO("deallocing XTileLayerInfo: %p", this);
    if (_ownTiles && _tiles)
    {
        free(_tiles);
        _tiles = nullptr;
    }
}

ValueMap& XTileLayerInfo::getProperties()
{
    return _properties;
}

void XTileLayerInfo::setProperties(ValueMap var)
{
    _properties = var;
}

// implementation XTilesetInfo
XTilesetInfo::XTilesetInfo()
    :_firstGid(0)
    ,_tileSize(Size::ZERO)
    ,_spacing(0)
    ,_margin(0)
    ,_imageSize(Size::ZERO)
{
}

XTilesetInfo::~XTilesetInfo()
{
    CCLOGINFO("deallocing XTilesetInfo: %p", this);
}

Rect XTilesetInfo::getRectForGID(uint32_t gid)
{
    Rect rect;
    rect.size = _tileSize;
    gid &= kXTileFlippedMask;
    gid = gid - _firstGid;
    // max_x means the column count in tile map
    // in the origin:
    // max_x = (int)((_imageSize.width - _margin*2 + _spacing) / (_tileSize.width + _spacing));
    // but in editor "Tiled", _margin variable only effect the left side
    // for compatible with "Tiled", change the max_x calculation
    int max_x = (int)((_imageSize.width - _margin + _spacing) / (_tileSize.width + _spacing));
    
    rect.origin.x = (gid % max_x) * (_tileSize.width + _spacing) + _margin;
    rect.origin.y = (gid / max_x) * (_tileSize.height + _spacing) + _margin;
    return rect;
}

// implementation XTileMapInfo

XTileMapInfo * XTileMapInfo::create(const std::string& tmxFile)
{
    XTileMapInfo *ret = new (std::nothrow) XTileMapInfo();
    if (ret->initWithTMXFile(tmxFile))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

XTileMapInfo * XTileMapInfo::createWithXML(const std::string& tmxString, const std::string& resourcePath)
{
    XTileMapInfo *ret = new (std::nothrow) XTileMapInfo();
    if (ret->initWithXML(tmxString, resourcePath))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void XTileMapInfo::internalInit(const std::string& tmxFileName, const std::string& resourcePath)
{
    if (!tmxFileName.empty())
    {
        _TMXFileName = FileUtils::getInstance()->fullPathForFilename(tmxFileName);
    }
    
    if (!resourcePath.empty())
    {
        _resources = resourcePath;
    }
    
    _objectGroups.reserve(4);

    // tmp vars
    _currentString = "";
    _storingCharacters = false;
    _layerAttribs = XTileLayerAttribNone;
    _parentElement = XTilePropertyNone;
    _currentFirstGID = -1;
}

bool XTileMapInfo::initWithXML(const std::string& tmxString, const std::string& resourcePath)
{
    internalInit("", resourcePath);
    return parseXMLString(tmxString);
}

bool XTileMapInfo::initWithTMXFile(const std::string& tmxFile)
{
    internalInit(tmxFile, "");
    return parseXMLFile(_TMXFileName);
}

XTileMapInfo::XTileMapInfo()
: _orientation(XTileOrientationOrtho)
, _staggerAxis(XTileStaggerAxis_Y)
, _staggerIndex(XTileStaggerIndex_Even)
, _hexSideLength(0)
, _mapSize(Size::ZERO)
, _tileSize(Size::ZERO)
, _parentElement(0)
, _parentGID(0)
, _layerAttribs(0)
, _storingCharacters(false)
, _xmlTileIndex(0)
, _currentFirstGID(-1)
, _recordFirstGID(true)
{
}

XTileMapInfo::~XTileMapInfo()
{
    CCLOGINFO("deallocing XTileMapInfo: %p", this);
}

bool XTileMapInfo::parseXMLString(const std::string& xmlString)
{
    size_t len = xmlString.size();
    if (len <= 0)
        return false;

    SAXParser parser;

    if (false == parser.init("UTF-8") )
    {
        return false;
    }

    parser.setDelegator(this);

    return parser.parse(xmlString.c_str(), len);
}

bool XTileMapInfo::parseXMLFile(const std::string& xmlFilename)
{
    SAXParser parser;
    
    if (false == parser.init("UTF-8") )
    {
        return false;
    }
    
    parser.setDelegator(this);
    auto fullPath = FileUtils::getInstance()->fullPathForFilename(xmlFilename);
    CCASSERT(FileUtils::getInstance()->isFileExist(fullPath), "XTileMapInfo::parseXMLFile xml file not exists");
    return parser.parse(fullPath);
}

// the XML parser calls here with all the elements
void XTileMapInfo::startElement(void* /*ctx*/, const char *name, const char **atts)
{    
    XTileMapInfo *tmxMapInfo = this;
    std::string elementName = name;
    ValueMap attributeDict;
    if (atts && atts[0])
    {
        for (int i = 0; atts[i]; i += 2)
        {
            std::string key = atts[i];
            std::string value = atts[i+1];
            attributeDict.emplace(key, Value(value));
        }
    }
    if (elementName == "map")
    {
        std::string version = attributeDict["version"].asString();
        if ( version != "1.0")
        {
            CCLOG("cocos2d: TMXFormat: Unsupported TMX version: %s", version.c_str());
        }
        std::string orientationStr = attributeDict["orientation"].asString();
        if (orientationStr == "orthogonal") {
            tmxMapInfo->setOrientation(XTileOrientationOrtho);
        }
        else if (orientationStr  == "isometric") {
            tmxMapInfo->setOrientation(XTileOrientationIso);
        }
        else if (orientationStr == "hexagonal") {
            tmxMapInfo->setOrientation(XTileOrientationHex);
        }
        else if (orientationStr == "staggered") {
            tmxMapInfo->setOrientation(XTileOrientationStaggered);
        }
        else {
            CCLOG("cocos2d: TMXFomat: Unsupported orientation: %d", tmxMapInfo->getOrientation());
        }
        
        std::string staggerAxisStr = attributeDict["staggeraxis"].asString();
        if (staggerAxisStr == "x") {
            tmxMapInfo->setStaggerAxis(XTileStaggerAxis_X);
        }
        else if (staggerAxisStr  == "y") {
            tmxMapInfo->setStaggerAxis(XTileStaggerAxis_Y);
        }

        std::string staggerIndex = attributeDict["staggerindex"].asString();
        if (staggerIndex == "odd") {
            tmxMapInfo->setStaggerIndex(XTileStaggerIndex_Odd);
        }
        else if (staggerIndex == "even") {
            tmxMapInfo->setStaggerIndex(XTileStaggerIndex_Even);
        }


        float hexSideLength = attributeDict["hexsidelength"].asFloat();
        tmxMapInfo->setHexSideLength(hexSideLength);

        Size s;
        s.width = attributeDict["width"].asFloat();
        s.height = attributeDict["height"].asFloat();
        tmxMapInfo->setMapSize(s);

        s.width = attributeDict["tilewidth"].asFloat();
        s.height = attributeDict["tileheight"].asFloat();
        tmxMapInfo->setTileSize(s);

        

        // The parent element is now "map"
        tmxMapInfo->setParentElement(XTilePropertyMap);
    } 
    else if (elementName == "tileset") 
    {
        // If this is an external tileset then start parsing that
        std::string externalTilesetFilename = attributeDict["source"].asString();
        if (externalTilesetFilename != "")
        {
            _externalTilesetFilename = externalTilesetFilename;

            // Tileset file will be relative to the map file. So we need to convert it to an absolute path
            if (_TMXFileName.find_last_of('/') != string::npos)
            {
                string dir = _TMXFileName.substr(0, _TMXFileName.find_last_of('/') + 1);
                externalTilesetFilename = dir + externalTilesetFilename;
            }
            else 
            {
                externalTilesetFilename = _resources + "/" + externalTilesetFilename;
            }
            externalTilesetFilename = FileUtils::getInstance()->fullPathForFilename(externalTilesetFilename);
            
            _currentFirstGID = attributeDict["firstgid"].asInt();
            if (_currentFirstGID < 0)
            {
                _currentFirstGID = 0;
            }
            _recordFirstGID = false;
            _externalTilesetFullPath = externalTilesetFilename;
            tmxMapInfo->parseXMLFile(externalTilesetFilename);
        }
        else
        {
            XTilesetInfo *tileset = new (std::nothrow) XTilesetInfo();
            tileset->_name = attributeDict["name"].asString();
            
            if (_recordFirstGID)
            {
                // unset before, so this is tmx file.
                tileset->_firstGid = attributeDict["firstgid"].asInt();
                
                if (tileset->_firstGid < 0)
                {
                    tileset->_firstGid = 0;
                }
            }
            else
            {
                tileset->_firstGid = _currentFirstGID;
                _currentFirstGID = 0;
            }
            
            tileset->_spacing = attributeDict["spacing"].asInt();
            tileset->_margin = attributeDict["margin"].asInt();
            Size s;
            s.width = attributeDict["tilewidth"].asFloat();
            s.height = attributeDict["tileheight"].asFloat();
            tileset->_tileSize = s;

            tmxMapInfo->getTilesets().pushBack(tileset);
            tileset->release();
        }
    }
    else if (elementName == "tile")
    {
        if (tmxMapInfo->getParentElement() == XTilePropertyLayer)
        {
            XTileLayerInfo* layer = tmxMapInfo->getLayers().back();
            Size layerSize = layer->_layerSize;
            uint32_t gid = static_cast<uint32_t>(attributeDict["gid"].asUnsignedInt());
            int tilesAmount = layerSize.width*layerSize.height;
            
            if (_xmlTileIndex < tilesAmount)
            {
                layer->_tiles[_xmlTileIndex++] = gid;
            }
        }
        else
        {
            XTilesetInfo* info = tmxMapInfo->getTilesets().back();
            tmxMapInfo->setParentGID(info->_firstGid + attributeDict["id"].asInt());
            tmxMapInfo->getTileProperties()[tmxMapInfo->getParentGID()] = Value(ValueMap());
            tmxMapInfo->setParentElement(XTilePropertyTile);
        }
    }
    else if (elementName == "layer")
    {
        XTileLayerInfo *layer = new (std::nothrow) XTileLayerInfo();
        layer->_name = attributeDict["name"].asString();

        Size s;
        s.width = attributeDict["width"].asFloat();
        s.height = attributeDict["height"].asFloat();
        layer->_layerSize = s;

        Value& visibleValue = attributeDict["visible"];
        layer->_visible = visibleValue.isNull() ? true : visibleValue.asBool();

        Value& opacityValue = attributeDict["opacity"];
        layer->_opacity = opacityValue.isNull() ? 255 : (unsigned char)(255.0f * opacityValue.asFloat());

        float x = attributeDict["x"].asFloat();
        float y = attributeDict["y"].asFloat();
        layer->_offset.set(x, y);

        tmxMapInfo->getLayers().pushBack(layer);
        layer->release();

        // The parent element is now "layer"
        tmxMapInfo->setParentElement(XTilePropertyLayer);
    } 
    else if (elementName == "objectgroup")
    {
        XTileObjectGroup *objectGroup = new (std::nothrow) XTileObjectGroup();
        objectGroup->setGroupName(attributeDict["name"].asString());
        Vec2 positionOffset;
        positionOffset.x = attributeDict["x"].asFloat() * tmxMapInfo->getTileSize().width;
        positionOffset.y = attributeDict["y"].asFloat() * tmxMapInfo->getTileSize().height;
        objectGroup->setPositionOffset(positionOffset);

        tmxMapInfo->getObjectGroups().pushBack(objectGroup);
        objectGroup->release();

        // The parent element is now "objectgroup"
        tmxMapInfo->setParentElement(XTilePropertyObjectGroup);
    }
    else if (elementName == "tileoffset")
    {
        XTilesetInfo* tileset = tmxMapInfo->getTilesets().back();
        
        double tileOffsetX = attributeDict["x"].asDouble();
        
        double tileOffsetY = attributeDict["y"].asDouble();
        
        tileset->_tileOffset = Vec2(tileOffsetX, tileOffsetY);
        
    }
    else if (elementName == "image")
    {
        XTilesetInfo* tileset = tmxMapInfo->getTilesets().back();

        // build full path
        std::string imagename = attributeDict["source"].asString();
        tileset->_originSourceImage = imagename;

        if (!_externalTilesetFullPath.empty())
        {
            string dir = _externalTilesetFullPath.substr(0, _externalTilesetFullPath.find_last_of('/') + 1);
            tileset->_sourceImage = dir + imagename;
        }
        else if (_TMXFileName.find_last_of('/') != string::npos)
        {
            string dir = _TMXFileName.substr(0, _TMXFileName.find_last_of('/') + 1);
            tileset->_sourceImage = dir + imagename;
        }
        else 
        {
            tileset->_sourceImage = _resources + (_resources.size() ? "/" : "") + imagename;
        }
    } 
    else if (elementName == "data")
    {
        std::string encoding = attributeDict["encoding"].asString();
        std::string compression = attributeDict["compression"].asString();

        if (encoding == "")
        {
            tmxMapInfo->setLayerAttribs(tmxMapInfo->getLayerAttribs() | XTileLayerAttribNone);
            
            XTileLayerInfo* layer = tmxMapInfo->getLayers().back();
            Size layerSize = layer->_layerSize;
            int tilesAmount = layerSize.width*layerSize.height;

            uint32_t *tiles = (uint32_t*) malloc(tilesAmount*sizeof(uint32_t));
            // set all value to 0
            memset(tiles, 0, tilesAmount*sizeof(int));

            layer->_tiles = tiles;
        }
        else if (encoding == "base64")
        {
            int layerAttribs = tmxMapInfo->getLayerAttribs();
            tmxMapInfo->setLayerAttribs(layerAttribs | XTileLayerAttribBase64);
            tmxMapInfo->setStoringCharacters(true);

            if (compression == "gzip")
            {
                layerAttribs = tmxMapInfo->getLayerAttribs();
                tmxMapInfo->setLayerAttribs(layerAttribs | XTileLayerAttribGzip);
            } else
            if (compression == "zlib")
            {
                layerAttribs = tmxMapInfo->getLayerAttribs();
                tmxMapInfo->setLayerAttribs(layerAttribs | XTileLayerAttribZlib);
            }
            CCASSERT( compression == "" || compression == "gzip" || compression == "zlib", "XTile: unsupported compression method" );
        }
        else if (encoding == "csv")
        {
            int layerAttribs = tmxMapInfo->getLayerAttribs();
            tmxMapInfo->setLayerAttribs(layerAttribs | XTileLayerAttribCSV);
            tmxMapInfo->setStoringCharacters(true);
        }
    }
    else if (elementName == "object")
    {
        XTileObjectGroup* objectGroup = tmxMapInfo->getObjectGroups().back();

        // The value for "type" was blank or not a valid class name
        // Create an instance of TMXObjectInfo to store the object and its properties
        ValueMap dict;
        // Parse everything automatically
        const char* keys[] = {"name", "type", "width", "height", "gid", "id"};
        
        for (const auto& key : keys)
        {
            Value value = attributeDict[key];
            dict[key] = value;
        }

        // But X and Y since they need special treatment
        // X
        int x = attributeDict["x"].asInt();
        // Y
        int y = attributeDict["y"].asInt();
        
        Vec2 p(x + objectGroup->getPositionOffset().x, _mapSize.height * _tileSize.height - y  - objectGroup->getPositionOffset().y - attributeDict["height"].asInt());
        p = CC_POINT_PIXELS_TO_POINTS(p);
        dict["x"] = Value(p.x);
        dict["y"] = Value(p.y);
        
        int width = attributeDict["width"].asInt();
        int height = attributeDict["height"].asInt();
        Size s(width, height);
        s = CC_SIZE_PIXELS_TO_POINTS(s);
        dict["width"] = Value(s.width);
        dict["height"] = Value(s.height);

        dict["rotation"] = attributeDict["rotation"].asDouble();

        // Add the object to the objectGroup
        objectGroup->getObjects().push_back(Value(dict));

        // The parent element is now "object"
        tmxMapInfo->setParentElement(XTilePropertyObject);
    } 
    else if (elementName == "property")
    {
        if ( tmxMapInfo->getParentElement() == XTilePropertyNone ) 
        {
            CCLOG( "TMX tile map: Parent element is unsupported. Cannot add property named '%s' with value '%s'",
                  attributeDict["name"].asString().c_str(), attributeDict["value"].asString().c_str() );
        } 
        else if ( tmxMapInfo->getParentElement() == XTilePropertyMap )
        {
            // The parent element is the map
            Value value = attributeDict["value"];
            std::string key = attributeDict["name"].asString();
            tmxMapInfo->getProperties().emplace(key, value);
        }
        else if ( tmxMapInfo->getParentElement() == XTilePropertyLayer )
        {
            // The parent element is the last layer
            XTileLayerInfo* layer = tmxMapInfo->getLayers().back();
            Value value = attributeDict["value"];
            std::string key = attributeDict["name"].asString();
            // Add the property to the layer
            layer->getProperties().emplace(key, value);
        }
        else if ( tmxMapInfo->getParentElement() == XTilePropertyObjectGroup ) 
        {
            // The parent element is the last object group
            XTileObjectGroup* objectGroup = tmxMapInfo->getObjectGroups().back();
            Value value = attributeDict["value"];
            std::string key = attributeDict["name"].asString();
            objectGroup->getProperties().emplace(key, value);
        }
        else if ( tmxMapInfo->getParentElement() == XTilePropertyObject )
        {
            // The parent element is the last object
            XTileObjectGroup* objectGroup = tmxMapInfo->getObjectGroups().back();
            ValueMap& dict = objectGroup->getObjects().rbegin()->asValueMap();

            std::string propertyName = attributeDict["name"].asString();
            dict[propertyName] = attributeDict["value"];
        }
        else if ( tmxMapInfo->getParentElement() == XTilePropertyTile ) 
        {
            ValueMap& dict = tmxMapInfo->getTileProperties().at(tmxMapInfo->getParentGID()).asValueMap();

            std::string propertyName = attributeDict["name"].asString();
            dict[propertyName] = attributeDict["value"];
        }
    }
    else if (elementName == "polygon") 
    {
        // find parent object's dict and add polygon-points to it
        XTileObjectGroup* objectGroup = _objectGroups.back();
        ValueMap& dict = objectGroup->getObjects().rbegin()->asValueMap();

        // get points value string
        std::string value = attributeDict["points"].asString();
        if (!value.empty())
        {
            ValueVector pointsArray;
            pointsArray.reserve(10);

            // parse points string into a space-separated set of points
            stringstream pointsStream(value);
            string pointPair;
            while (std::getline(pointsStream, pointPair, ' '))
            {
                // parse each point combo into a comma-separated x,y point
                stringstream pointStream(pointPair);
                string xStr, yStr;
                
                ValueMap pointDict;

                // set x
                if (std::getline(pointStream, xStr, ','))
                {
                    int x = atoi(xStr.c_str()) + (int)objectGroup->getPositionOffset().x;
                    pointDict["x"] = Value(x);
                }

                // set y
                if (std::getline(pointStream, yStr, ','))
                {
                    int y = atoi(yStr.c_str()) + (int)objectGroup->getPositionOffset().y;
                    pointDict["y"] = Value(y);
                }
                
                // add to points array
                pointsArray.push_back(Value(pointDict));
            }
            
            dict["points"] = Value(pointsArray);
        }
    } 
    else if (elementName == "polyline")
    {
        // find parent object's dict and add polyline-points to it
        XTileObjectGroup* objectGroup = _objectGroups.back();
        ValueMap& dict = objectGroup->getObjects().rbegin()->asValueMap();
        
        // get points value string
        std::string value = attributeDict["points"].asString();
        if (!value.empty())
        {
            ValueVector pointsArray;
            pointsArray.reserve(10);
            
            // parse points string into a space-separated set of points
            stringstream pointsStream(value);
            string pointPair;
            while (std::getline(pointsStream, pointPair, ' '))
            {
                // parse each point combo into a comma-separated x,y point
                stringstream pointStream(pointPair);
                string xStr, yStr;
                
                ValueMap pointDict;
                
                // set x
                if (std::getline(pointStream, xStr, ','))
                {
                    int x = atoi(xStr.c_str()) + (int)objectGroup->getPositionOffset().x;
                    pointDict["x"] = Value(x);
                }
                
                // set y
                if (std::getline(pointStream, yStr, ','))
                {
                    int y = atoi(yStr.c_str()) + (int)objectGroup->getPositionOffset().y;
                    pointDict["y"] = Value(y);
                }
                
                // add to points array
                pointsArray.push_back(Value(pointDict));
            }
            
            dict["polylinePoints"] = Value(pointsArray);
        }
    }
}

void XTileMapInfo::endElement(void* /*ctx*/, const char *name)
{
    XTileMapInfo *tmxMapInfo = this;
    std::string elementName = name;

    if (elementName == "data")
    {
        if (tmxMapInfo->getLayerAttribs() & XTileLayerAttribBase64)
        {
            tmxMapInfo->setStoringCharacters(false);
            
            XTileLayerInfo* layer = tmxMapInfo->getLayers().back();
            
            std::string currentString = tmxMapInfo->getCurrentString();
            unsigned char *buffer;
            auto len = base64Decode((unsigned char*)currentString.c_str(), (unsigned int)currentString.length(), &buffer);
            if (!buffer)
            {
                CCLOG("cocos2d: TiledMap: decode data error");
                return;
            }
            
            if (tmxMapInfo->getLayerAttribs() & (XTileLayerAttribGzip | XTileLayerAttribZlib))
            {
                unsigned char *deflated = nullptr;
                Size s = layer->_layerSize;
                // int sizeHint = s.width * s.height * sizeof(uint32_t);
                ssize_t sizeHint = s.width * s.height * sizeof(unsigned int);
                
                ssize_t CC_UNUSED inflatedLen = ZipUtils::inflateMemoryWithHint(buffer, len, &deflated, sizeHint);
                CCASSERT(inflatedLen == sizeHint, "inflatedLen should be equal to sizeHint!");
                
                free(buffer);
                buffer = nullptr;
                
                if (!deflated)
                {
                    CCLOG("cocos2d: TiledMap: inflate data error");
                    return;
                }
                
                layer->_tiles = reinterpret_cast<uint32_t*>(deflated);
            }
            else
            {
                layer->_tiles = reinterpret_cast<uint32_t*>(buffer);
            }
            
            tmxMapInfo->setCurrentString("");
        }
        else if (tmxMapInfo->getLayerAttribs() & XTileLayerAttribCSV)
        {
            unsigned char *buffer;

            XTileLayerInfo* layer = tmxMapInfo->getLayers().back();

            tmxMapInfo->setStoringCharacters(false);
            std::string currentString = tmxMapInfo->getCurrentString();

            vector<string> gidTokens;
            istringstream filestr(currentString);
            string sRow;
            while(getline(filestr, sRow, '\n')) {
                string sGID;
                istringstream rowstr(sRow);
                while (getline(rowstr, sGID, ',')) {
                    gidTokens.push_back(sGID);
                }
            }

            // 32-bits per gid
            buffer = (unsigned char*)malloc(gidTokens.size() * 4);
            if (!buffer)
            {
                CCLOG("cocos2d: TiledMap: CSV buffer not allocated.");
                return;
            }

            uint32_t* bufferPtr = reinterpret_cast<uint32_t*>(buffer);
            for(const auto& gidToken : gidTokens) {
                auto tileGid = (uint32_t)strtoul(gidToken.c_str(), nullptr, 10);
                *bufferPtr = tileGid;
                bufferPtr++;
            }

            layer->_tiles = reinterpret_cast<uint32_t*>(buffer);

            tmxMapInfo->setCurrentString("");
        }
        else if (tmxMapInfo->getLayerAttribs() & XTileLayerAttribNone)
        {
            _xmlTileIndex = 0;
        }
    }
    else if (elementName == "map")
    {
        // The map element has ended
        tmxMapInfo->setParentElement(XTilePropertyNone);
    }    
    else if (elementName == "layer")
    {
        // The layer element has ended
        tmxMapInfo->setParentElement(XTilePropertyNone);
    }
    else if (elementName == "objectgroup")
    {
        // The objectgroup element has ended
        tmxMapInfo->setParentElement(XTilePropertyNone);
    } 
    else if (elementName == "object") 
    {
        // The object element has ended
        tmxMapInfo->setParentElement(XTilePropertyNone);
    }
    else if (elementName == "tileset")
    {
        _recordFirstGID = true;
    }
}

void XTileMapInfo::textHandler(void* /*ctx*/, const char *ch, size_t len)
{
    XTileMapInfo *tmxMapInfo = this;
    std::string text(ch, 0, len);

    if (tmxMapInfo->isStoringCharacters())
    {
        std::string currentString = tmxMapInfo->getCurrentString();
        currentString += text;
        tmxMapInfo->setCurrentString(currentString);
    }
}
