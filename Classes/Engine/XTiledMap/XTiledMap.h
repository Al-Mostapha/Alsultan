/****************************************************************************
Copyright (c) 2009-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2016 Chukong Technologies Inc.
Copyright (c) 2020 cocos2d-lua.org

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
#pragma once

#include "2d/CCNode.h"
#include "XTiledObjectGroup.h"
#include "base/CCValue.h"

USING_NS_CC;

class XTiledLayer;
class XTiledLayerInfo;
class XTilesetInfo;
class XTiledMapInfo;

/**
 * @addtogroup _2d
 * @{
 */

/** Possible orientations of the TMX map. */
enum
{
    /** Orthogonal orientation. */
    XTiledOrientationOrtho,

    /** Hexagonal orientation. */
    XTiledOrientationHex,

    /** Isometric orientation. */
    XTiledOrientationIso,
    
    /** Isometric staggered orientation. */
    XTiledOrientationStaggered,
};

/** Possible stagger axis of the TMX map. */
enum
{
    /** Stagger Axis x. */
    XTiledStaggerAxis_X,
    
    /** Stagger Axis y. */
    XTiledStaggerAxis_Y,
};

/** Possible stagger index of the TMX map. */
enum
{
    /** Stagger Index: Odd */
    XTiledStaggerIndex_Odd,

    /** Stagger Index: Even */
    XTiledStaggerIndex_Even,
};

/** @brief TMXTiledMap knows how to parse and render a TMX map.

 * It adds support for the TMX tiled map format used by http://www.mapeditor.org
 * It supports isometric, hexagonal and orthogonal tiles.
 * It also supports object groups, objects, and properties.

 * Features:
 * - Each tile will be treated as an Sprite.
 * - The sprites are created on demand. They will be created only when you call "layer->tileAt(position)".
 * - Each tile can be rotated / moved / scaled / tinted / "opaqued", since each tile is a Sprite.
 * - Tiles can be added/removed in runtime.
 * - The z-order of the tiles can be modified in runtime.
 * - Each tile has an anchorPoint of (0,0).
 * - The anchorPoint of the TMXTileMap is (0,0).
 * - The TMX layers will be added as a child.
 * - The TMX layers will be aliased by default.
 * - The tileset image will be loaded using the TextureCache.
 * - Each tile will have a unique tag.
 * - Each tile will have a unique z value. top-left: z=1, bottom-right: z=max z.
 * - Each object group will be treated as an MutableArray.
 * - Object class which will contain all the properties in a dictionary.
 * - Properties can be assigned to the Map, Layer, Object Group, and Object.

 * Limitations:
 * - It only supports one tileset per layer.
 * - Embedded images are not supported.
 * - It only supports the XML format (the JSON format is not supported).

 * Technical description:
 * Each layer is created using an TMXLayer (subclass of SpriteBatchNode). If you have 5 layers, then 5 TMXLayer will be created,
 * unless the layer visibility is off. In that case, the layer won't be created at all.
 * You can obtain the layers (TMXLayer objects) at runtime by:
 * - map->getChildByTag(tag_number);  // 0=1st layer, 1=2nd layer, 2=3rd layer, etc...
 * - map->getLayer(name_of_the_layer);

 * Each object group is created using a TMXObjectGroup which is a subclass of MutableArray.
 * You can obtain the object groups at runtime by:
 * - map->getObjectGroup(name_of_the_object_group);

 * Each object is a TMXObject.

 * Each property is stored as a key-value pair in an MutableDictionary.
 * You can obtain the properties at runtime by:

 * map->getProperty(name_of_the_property);
 * layer->getProperty(name_of_the_property);
 * objectGroup->getProperty(name_of_the_property);
 * object->getProperty(name_of_the_property);

 * @since v0.8.1
 */
class CC_DLL XTiledMap : public Node
{
public:
    /** Creates a TMX Tiled Map with a TMX file.
     *
     * @param tmxFile A TMX file.
     * @return An autorelease object.
     */
    static XTiledMap* create(const std::string& tmxFile, bool setupTiles = true);

    /** Initializes a TMX Tiled Map with a TMX formatted XML string and a path to TMX resources. 
     *
     * @param tmxString A TMX formatted XML string.
     * @param resourcePath The path to TMX resources.
     * @return An autorelease object.
     * @js NA
     */
    static XTiledMap* createWithXML(const std::string& tmxString, const std::string& resourcePath, bool setupTiles = true);

    /** Return the TMXLayer for the specific layer. 
     *
     * @param layerName A specific layer.
     * @return The TMXLayer for the specific layer.
     */
    XTiledLayer* getLayer(const std::string& layerName) const;

    /** Return the TMXObjectGroup for the specific group. 
     *
     * @param groupName The group Name.
     * @return A Type of TMXObjectGroup.
     */
    XTiledObjectGroup* getObjectGroup(const std::string& groupName) const;

    /** Return the value for the specific property name. 
     *
     * @param propertyName The specific property name.
     * @return Return the value for the specific property name.
     */
    Value getProperty(const std::string& propertyName) const;

    /** Return properties dictionary for tile GID. 
     *
     * @param GID The tile GID.
     * @return Return properties dictionary for tile GID.
     */
    Value getPropertiesForGID(int GID) const;

    /** The map's size property measured in tiles. */
    const Size& getMapSize() const { return _mapSize; }
    void setMapSize(const Size& mapSize) { _mapSize = mapSize; }

    /** The tiles's size property measured in pixels. */
    const Size& getTileSize() const { return _tileSize; }
    void setTileSize(const Size& tileSize) { _tileSize = tileSize; }

    /** Map orientation */
    int getMapOrientation() const { return _mapOrientation; }
    void setMapOrientation(int mapOrientation) { _mapOrientation = mapOrientation; }
    /** Map staggerAxis */
    int getStaggerAxis() const { return _staggerAxis; }
    void setStaggerAxis(int staggerAxis) { _staggerAxis = staggerAxis; }
    /** Map staggerIndex */
    int getStaggerIndex() const { return _staggerIndex; }
    void setStaggerIndex(int staggerIndex) { _staggerIndex = staggerIndex; }
    /** Map hexSideLength */
    int getHexSideLength() const { return _hexSideLength; }
    void setHexSideLength(int hexSideLength) { _hexSideLength = hexSideLength; }

    /** Get the Object groups */
    Vector<XTiledObjectGroup*>& getObjectGroups() { return _objectGroups; }
    void setObjectGroups(const Vector<XTiledObjectGroup*>& groups) { _objectGroups = groups; }
    
    /** Properties */
    ValueMap& getProperties() { return _properties; }
    void setProperties(const ValueMap& properties) { _properties = properties; }
    
    /** Tilesets */
    const Vector<XTilesetInfo*>& getTilesets() const { return _tilesets; }
    XTilesetInfo *getTilesetByGID(uint32_t gid) const;
    
    /** Get the description.
     * @js NA
     */
    virtual std::string getDescription() const override;

    const std::string& getResourceFile() const { return _tmxFile; }

CC_CONSTRUCTOR_ACCESS:
    /**
     * @js ctor
     */
    XTiledMap();
    /**
     * @js NA
     * @lua NA
     */
    virtual ~XTiledMap();
    
    /** initializes a TMX Tiled Map with a TMX file */
    bool initWithTMXFile(const std::string& tmxFile);
    
    /** initializes a TMX Tiled Map with a TMX formatted XML string and a path to TMX resources */
    bool initWithXML(const std::string& tmxString, const std::string& resourcePath);

protected:
    void buildWithMapInfo(XTiledMapInfo* mapInfo);
    Node *createChild(Ref *childInfo);
    XTiledLayer *findLayer(const Node *parent, const std::string& layerName) const;
    Vec2 getPositionForTileObject(std::string& gridOrientation, Size& gridSize, const Vec2& pos);

    /** the map's size property measured in tiles */
    Size _mapSize;
    /** the tiles's size property measured in pixels */
    Size _tileSize;
    /** map orientation */
    int _mapOrientation;
    /** Stagger Axis */
    int _staggerAxis;
    /** Stagger Index */
    int _staggerIndex;
    /** Hex side length*/
    int _hexSideLength;
    /** object groups */
    Vector<XTiledObjectGroup*> _objectGroups;
    /** properties */
    ValueMap _properties;
    
    /** tilesets info */
    Vector<XTilesetInfo*> _tilesets;
    /** tile properties */
    ValueMapIntKey _tileProperties;

    std::string _tmxFile;
    bool _setupTiles;
private:
    CC_DISALLOW_COPY_AND_ASSIGN(XTiledMap);
};

// end of tilemap_parallax_nodes group
/// @}

