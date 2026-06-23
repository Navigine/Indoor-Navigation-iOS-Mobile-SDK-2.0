#import <Foundation/Foundation.h>

/**
 * Enum defining types of signals used in measurements.
 * Referenced from ``NCSignalMeasurement``.
 */
typedef NS_ENUM(NSInteger, NCSignalType)
{
    /**
     * Wi-Fi signal type. <a href="https://en.wikipedia.org/wiki/Wi-Fi">Wi-Fi</a>.
     */
    NCSignalTypeWIFI,
    /**
     * Bluetooth Low Energy (BLE) beacon signal type. <a href="https://en.wikipedia.org/wiki/Bluetooth_Low_Energy#BLE_Beacons">iBeacon</a>.
     */
    NCSignalTypeBEACON,
    /**
     * Bluetooth signal type. <a href="https://en.wikipedia.org/wiki/Bluetooth">Bluetooth</a>.
     */
    NCSignalTypeBLUETOOTH,
    /**
     * Eddystone beacon signal type. <a href="https://en.wikipedia.org/wiki/Eddystone_(Google)">Eddystone</a>.
     */
    NCSignalTypeEDDYSTONE,
    /**
     * Wi-Fi Round-Trip Time signal type. <a href="https://en.wikipedia.org/wiki/Round-trip_delay#Wi-Fi_RTT">Wi-Fi_RTT</a>.
     */
    NCSignalTypeWIFIRTT,
};
