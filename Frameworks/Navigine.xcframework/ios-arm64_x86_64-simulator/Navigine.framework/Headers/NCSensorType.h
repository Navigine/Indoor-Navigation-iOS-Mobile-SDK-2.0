#import <Foundation/Foundation.h>

/**
 * @file NCSensorType.h
 * @brief @copybrief NCSensorType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Enum defining types of sensors used in measurements.
 *
 * Referenced from @see SensorMeasurement "SensorMeasurement".
 *
 */
typedef NS_ENUM(NSInteger, NCSensorType)
{
    /**
     * @brief Accelerometer sensor type. <a href="https://en.wikipedia.org/wiki/Accelerometer ">Accelerometer</a>.
     */
    NCSensorTypeACCELEROMETER,
    /**
     * @brief Magnetometer sensor type. <a href="https://en.wikipedia.org/wiki/Magnetometer">Magnetometer</a>.
     */
    NCSensorTypeMAGNETOMETER,
    /**
     * @brief Gyroscope sensor type. <a href="https://en.wikipedia.org/wiki/Gyroscope">Gyroscope</a>.
     */
    NCSensorTypeGYROSCOPE,
    /**
     * @brief Barometer sensor type. <a href="https://en.wikipedia.org/wiki/Barometer">Barometer</a>.
     */
    NCSensorTypeBAROMETER,
    /**
     * @brief Location sensor type. <a href="https://en.wikipedia.org/wiki/Satellite_navigation">GNSS</a>.
     */
    NCSensorTypeLOCATION,
    /**
     * @brief Orientation sensor type
     */
    NCSensorTypeORIENTATION,
    /**
     * @brief NMEA GNSS sentence metadata. @see SensorMeasurement "SensorMeasurement" values: x = sentence number, y = satellite count, z unused.
     */
    NCSensorTypeNMEA,
    /**
     * @brief Odometer / wheel speed. Values: x = speed (m/s), y = accuracy if present else 0, z unused.
     */
    NCSensorTypeODOMETER,
    /**
     * @brief Raw GNSS vectors (pseudo-ranges, etc.) — summarized for the API. Values: x = pseudoRanges count, y = pseudoRangeRates count, z = satellitesPositions count.
     */
    NCSensorTypeGNSS,
};
