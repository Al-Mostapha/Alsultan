#pragma once
#include "2d/CCNode.h"
#include "2d/CCTMXObjectGroup.h"
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
    TMXOrientationOrtho,

    /** Hexagonal orientation. */
    TMXOrientationHex,

    /** Isometric orientation. */
    TMXOrientationIso,
    
    /** Isometric staggered orientation. */
    TMXOrientationStaggered,
};

/** Possible stagger axis of the TMX map. */
enum
{
    /** Stagger Axis x. */
    TMXStaggerAxis_X,
    
    /** Stagger Axis y. */
    TMXStaggerAxis_Y,
};

/** Possible stagger index of the TMX map. */
enum
{
    /** Stagger Index: Odd */
    TMXStaggerIndex_Odd,

    /** Stagger Index: Even */
    TMXStaggerIndex_Even,
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
class XTiledMap : public Node
{
public:
    /** Creates a TMX Tiled Map with a TMX file.
     *
     * @param tmxFile A TMX file.
     * @return An autorelease object.
     */
    static XTiledMap* create(const std::string& tmxFile);

    /** Initializes a TMX Tiled Map with a TMX formatted XML string and a path to TMX resources. 
     *
     * @param tmxString A TMX formatted XML string.
     * @param resourcePath The path to TMX resources.
     * @return An autorelease object.
     * @js NA
     */
    static XTiledMap* createWithXML(const std::string& tmxString, const std::string& resourcePath);

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
    TMXObjectGroup* getObjectGroup(const std::string& groupName) const;

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

    /** Assigns properties to argument value, returns true if it did found properties 
     * for that GID and did assigned a value, else it returns false.
     *
     * @param GID The tile GID.
     * @param value Argument value.
     * @return Return true if it did found properties for that GID and did assigned a value, else it returns false.
     */
    bool getPropertiesForGID(int GID, Value** value);

    /** The map's size property measured in tiles. 
     *
     * @return The map's size property measured in tiles.
     */
    const Size& getMapSize() const { return _mapSize; }
    
    /** Set the map's size property measured in tiles. 
     *
     * @param mapSize The map's size property measured in tiles.
     */
    void setMapSize(const Size& mapSize) { _mapSize = mapSize; }

    /** The tiles's size property measured in pixels. 
     *
     * @return The tiles's size property measured in pixels.
     */
    const Size& getTileSize() const { return _tileSize; }
    
    /** Set the tiles's size property measured in pixels. 
     *
     * @param tileSize The tiles's size property measured in pixels.
     */
    void setTileSize(const Size& tileSize) { _tileSize = tileSize; }

    /** Map orientation. 
     *
     * @return Map orientation.
     */
    int getMapOrientation() const { return _mapOrientation; }
    
    /** Set map orientation. 
     *
     * @param mapOrientation The map orientation.
     */
    void setMapOrientation(int mapOrientation) { _mapOrientation = mapOrientation; }

    /** Get the Object groups. 
     *
     * @return The object groups.
     */
    const Vector<TMXObjectGroup*>& getObjectGroups() const { return _objectGroups; }
    Vector<TMXObjectGroup*>& getObjectGroups() { return _objectGroups; }
    
    /** Set the object groups. 
     *
     * @param groups The object groups.
     */
    void setObjectGroups(const Vector<TMXObjectGroup*>& groups) {
        _objectGroups = groups;
    }
    
    /** Properties. 
     *
     * @return Properties.
     */
    ValueMap& getProperties() { return _properties; }
    
    /** Set the properties.
     *
     * @param properties A  Type of ValueMap to set the properties.
     */
    void setProperties(const ValueMap& properties) {
        _properties = properties;
    }
    
    /** Get the description.
     * @js NA
     */
    virtual std::string getDescription() const override;

    int  getLayerNum();
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
    XTiledLayer * parseLayer(XTiledLayerInfo *layerInfo, XTiledMapInfo *mapInfo);
    XTilesetInfo * tilesetForLayer(XTiledLayerInfo *layerInfo, XTiledMapInfo *mapInfo);
    void buildWithMapInfo(XTiledMapInfo* mapInfo);

    /** the map's size property measured in tiles */
    Size _mapSize;
    /** the tiles's size property measured in pixels */
    Size _tileSize;
    /** map orientation */
    int _mapOrientation;
    /** object groups */
    Vector<TMXObjectGroup*> _objectGroups;
    /** properties */
    ValueMap _properties;
    
    //! tile properties
    ValueMapIntKey _tileProperties;

    std::string _tmxFile;
    int _tmxLayerNum;

    static const int TMXLayerTag = 32768;

private:
    CC_DISALLOW_COPY_AND_ASSIGN(XTiledMap);

};

