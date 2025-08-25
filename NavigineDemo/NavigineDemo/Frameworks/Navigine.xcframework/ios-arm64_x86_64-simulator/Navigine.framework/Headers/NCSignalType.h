#import <Foundation/Foundation.h>

/**
 * @file NCSignalType.h
 * @brief @copybrief NCSignalType
 */
/**
 * @ingroup navigine_objc_classes
 * @ingroup navigine_objc_secondary_classes
 * @brief Enum defining types of signals used in measurements.
 *
 * Referenced from @see SignalMeasurement "SignalMeasurement".
 *
 */
typedef NS_ENUM(NSInteger, NCSignalType)
{
    /**
     * @brief Wi-Fi signal type. <a href="https://en.wikipedia.org/wiki/Wi-Fi">Wi-Fi</a>.
     */
    NCSignalTypeWIFI,
    /**
     * @brief Bluetooth Low Energy (BLE) beacon signal type. <a href="https://en.wikipedia.org/wiki/Bluetooth_Low_Energy#BLE_Beacons">iBeacon</a>.
     */
    NCSignalTypeBEACON,
    /**
     * @brief Bluetooth signal type. <a href="https://en.wikipedia.org/wiki/Bluetooth">Bluetooth</a>.
     */
    NCSignalTypeBLUETOOTH,
    /**
     * @brief Eddystone beacon signal type. <a href="https://en.wikipedia.org/wiki/Eddystone_(Google)">Eddystone</a>.
     */
    NCSignalTypeEDDYSTONE,
    /**
     * @brief Wi-Fi Round-Trip Time signal type. <a href="https://en.wikipedia.org/wiki/Round-trip_delay#Wi-Fi_RTT">Wi-Fi_RTT</a>.
     */
    NCSignalTypeWIFIRTT,
};
