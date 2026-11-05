import Foundation

class DebugController: UIViewController {
    
    @IBOutlet weak var mUuid: UILabel!
    @IBOutlet weak var mErrorCode: UILabel!
    @IBOutlet weak var mNavResult: UILabel!
    @IBOutlet weak var mAccellerometer: UILabel!
    @IBOutlet weak var mMagnetometer: UILabel!
    @IBOutlet weak var mGyro: UILabel!
    @IBOutlet weak var mGps: UILabel!
    @IBOutlet weak var mBleCount: UILabel!
    
    var textView: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        mUuid.text = "UUID: \(NCNavigineSdk.getDeviceId())"
        mErrorCode.text = "Error code: waiting for position"
        mNavResult.text = "Result: waiting for position"
        mAccellerometer.text = "Accelerometer: waiting for measurements"
        mMagnetometer.text = "Magnetometer: waiting for measurements"
        mGyro.text = "Gyroscope: waiting for measurements"
        mGps.text = "GPS: waiting for measurements"

        textView = UITextView()
        textView.translatesAutoresizingMaskIntoConstraints = false
        self.view.addSubview(textView)
        textView.text = "Waiting for signal measurements…"

        NavigineApp.mMeasurementManager?.add(self)
        NavigineApp.mNavigationManager?.add(self)
        
        textView.topAnchor.constraint(equalTo: self.mBleCount.bottomAnchor).isActive = true
        textView.bottomAnchor.constraint(equalTo: self.view.bottomAnchor).isActive = true
        textView.leftAnchor.constraint(equalTo: self.view.leftAnchor, constant: 20.0).isActive = true
        textView.rightAnchor.constraint(equalTo: self.view.rightAnchor).isActive = true
        textView.font = .systemFont(ofSize: 8)
        textView.isEditable = false
    }

}

extension DebugController: NCMeasurementListener {
    func onSensorMeasurementDetected(_ sensors: [NSNumber : NCSensorMeasurement]) {
        for el in sensors {
            switch el.value.type {
            case NCSensorType.ACCELEROMETER:
                mAccellerometer.text = "Accelerometer:  \(String(format: "%.2f", el.value.values.x)), \(String(format: "%.2f", el.value.values.y)), \(String(format: "%.2f", el.value.values.z))"
                break
            case NCSensorType.MAGNETOMETER:
                mMagnetometer.text = "Magnetometer:  \(String(format: "%.2f", el.value.values.x)), \(String(format: "%.2f", el.value.values.y)), \(String(format: "%.2f", el.value.values.z))"
                break
            case .GYROSCOPE:
                mGyro.text = "Gyroscope:  \(String(format: "%.2f", el.value.values.x)), \(String(format: "%.2f", el.value.values.y)), \(String(format: "%.2f", el.value.values.z))"
                break
            case .LOCATION:
                mGps.text = "GPS:  lat: \(String(format: "%.3f", el.value.values.x)) lon: \(String(format: "%.3f", el.value.values.y))"
                break
            case .BAROMETER:
                break
            case .ORIENTATION:
                break
            @unknown default:
                break
            }
        }
    }
    
    func onSignalMeasurementDetected(_ signals: [String : NCSignalMeasurement]){
        var signalsText: String = ""
        var i = 1
        let bleSignals = signals.values
            .filter { $0.type == NCSignalType.BEACON || $0.type == NCSignalType.EDDYSTONE }
            .sorted { $0.id < $1.id }

        for signal in bleSignals {
            let signalType = signal.type == NCSignalType.BEACON ? "Beacon" : "Eddystone"
            signalsText += "\(String(format: "%02d", i)))  \(signalType)  RSSI: \(signal.rssi)  ID: \(signal.id)\n"
            i += 1
        }

        if bleSignals.isEmpty {
            signalsText = "No BLE measurements received"
        }

        textView.text = signalsText
        mBleCount.text = "BLE devices: \(bleSignals.count)"
    }
}

extension DebugController: NCPositionListener {
    func onPositionUpdated(_ position: NCPosition) {
        if position.locationPoint != nil {
            mErrorCode.text = "Error code: 0   Sublocation: \(position.locationPoint!.sublocationId)"
            mNavResult.text = "Result:  x: \(position.locationPoint!.point.x)  y: \(position.locationPoint!.point.y)"
        } else {
            mErrorCode.text = "Error code: 0"
            mNavResult.text = "Result:  lat: \(position.point.latitude)  lon: \(position.point.longitude)"
        }
    }
    
    func onPositionError(_ error: Error?) {
        let code = (error as NSError?)?.code
        mErrorCode.text = "Error code: \(code.map { String($0) } ?? "unknown")   Sublocation:"
        mNavResult.text = "Result: \(error?.localizedDescription ?? "Position is not available")"
    }
}
