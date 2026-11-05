#import <Foundation/Foundation.h>

/**
 * Enum defining types of sensors used in measurements.
 * Referenced from ``NCSensorMeasurement``.
 */
typedef NS_ENUM(NSInteger, NCSensorType)
{
    /**
     * Accelerometer sensor type. <a href="https://en.wikipedia.org/wiki/Accelerometer ">Accelerometer</a>.
     */
    NCSensorTypeACCELEROMETER,
    /**
     * Magnetometer sensor type. <a href="https://en.wikipedia.org/wiki/Magnetometer">Magnetometer</a>.
     */
    NCSensorTypeMAGNETOMETER,
    /**
     * Gyroscope sensor type. <a href="https://en.wikipedia.org/wiki/Gyroscope">Gyroscope</a>.
     */
    NCSensorTypeGYROSCOPE,
    /**
     * Barometer sensor type. <a href="https://en.wikipedia.org/wiki/Barometer">Barometer</a>.
     */
    NCSensorTypeBAROMETER,
    /**
     * Location sensor type. <a href="https://en.wikipedia.org/wiki/Satellite_navigation">GNSS</a>.
     */
    NCSensorTypeLOCATION,
    /**
     * Orientation sensor type
     */
    NCSensorTypeORIENTATION,
    /**
     * NMEA GNSS sentence metadata. ``NCSensorMeasurement`` values: x = sentence number, y = satellite count, z unused.
     */
    NCSensorTypeNMEA,
    /**
     * Odometer / wheel speed. Values: x = speed (m/s), y = accuracy if present else 0, z unused.
     */
    NCSensorTypeODOMETER,
    /**
     * Raw GNSS vectors (pseudo-ranges, etc.) — summarized for the API. Values: x = pseudoRanges count, y = pseudoRangeRates count, z = satellitesPositions count.
     */
    NCSensorTypeGNSS,
};
