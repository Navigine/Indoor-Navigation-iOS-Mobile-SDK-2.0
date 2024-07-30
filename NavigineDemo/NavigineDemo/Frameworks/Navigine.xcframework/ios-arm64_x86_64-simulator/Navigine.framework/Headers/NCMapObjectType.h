#import <Foundation/Foundation.h>

/** Describe underlying type of map object */
typedef NS_ENUM(NSInteger, NCMapObjectType)
{
    /** (@see IconMapObject) */
    NCMapObjectTypeICON,
    /** (@see FlatIconMapObject) */
    NCMapObjectTypeFLATICON,
    /** (@see PolylineIconMapObject) */
    NCMapObjectTypePOLYLINE,
    /** (@see CircleMapObject) */
    NCMapObjectTypeCIRCLE,
};
