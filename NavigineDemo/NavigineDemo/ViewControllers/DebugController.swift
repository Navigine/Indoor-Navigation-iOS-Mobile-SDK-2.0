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
        textView = UITextView()
        textView.translatesAutoresizingMaskIntoConstraints = false
        self.view.addSubview(textView)
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
        for item in signals {
            let id = item.key.replacingOccurrences(of: "(", with: "").replacingOccurrences(of: ")", with: "").split(separator: ",")
            if item.value.type == NCSignalType.BEACON {
                signalsText += "\(String(format: "%02d", i)))  \(item.value.rssi)   \(String(format: "%05d", Int(String(id[0]))!))   \(String(format: "%05d", Int(String(id[1]))!))   \(id[2])\n"
            } else if item.value.type == NCSignalType.EDDYSTONE {
                signalsText += "\(String(format: "%02d", i)))  \(item.value.rssi)   \(id[0])   \(id[1])\n"
            }
            i += 1
        }
        
        textView.text = signalsText
    }
}

extension DebugController: NCPositionListener {
    func onPositionUpdated(_ position: NCPosition) {
        mErrorCode.text = "Error code: 0   Sublocation: \(position.sublocationId)"
        mNavResult.text = "Result:  x: \(position.point.x)  y: \(position.point.y)"
    }
    
    func onPositionError(_ error: Error?) {
        mErrorCode.text = "Error code:  Sublocation:"
        mNavResult.text = "Result:"
    }
}
