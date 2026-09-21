#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NCRouteLayerStatus)
{
    NCRouteLayerStatusIDLE,
    NCRouteLayerStatusROUTEUPDATED,
    NCRouteLayerStatusMISSINGGRAPH,
    NCRouteLayerStatusMISSINGLOCATION,
    NCRouteLayerStatusMISSINGPOSITION,
    NCRouteLayerStatusMISSINGROUTE,
    NCRouteLayerStatusMISSINGPROJECTION,
};
