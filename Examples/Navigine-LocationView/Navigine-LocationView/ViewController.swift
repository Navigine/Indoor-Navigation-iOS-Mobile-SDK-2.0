//
//  ViewController.swift
//  Navigine-LocationManager
//
//  Created by Elvira Khabibullina on 04.07.2024.
//

import UIKit
import Navigine

class ViewController: UIViewController {
    @IBOutlet weak var mLocationView: NCLocationView!

    private var sdk: NCNavigineSdk?
    private var locationManager: NCLocationManager?
    private var location: NCLocation?
    private var sublocation: NCSublocation?

    private let userHash = "1DE0-C579-7274-35E8"
    private let locationId: Int32 = 112
    private let serverUrl = "https://ips.navigine.com"

    private var floorLabel: UILabel!
    private var floorStepper: UIStepper!

    override func viewDidLoad() {
        super.viewDidLoad()
        setupUI()
        initSDK()
    }

    // MARK: - SDK init
    private func initSDK() {
        sdk = NCNavigineSdk.getInstance()
        sdk?.setServer(serverUrl)
        sdk?.setUserHash(userHash)
        locationManager = sdk?.getLocationManager()
        locationManager?.add(self)
        locationManager?.setLocationId(locationId)

        mLocationView.locationWindow.add(self as NCPickListener)
        mLocationView.locationWindow.add(self as NCInputListener)
    }

    // MARK: - UI
    private func setupUI() {
        // Floor controls
        floorLabel = UILabel()
        floorLabel.text = "Floor: 0"
        floorLabel.textAlignment = .center
        floorLabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(floorLabel)

        floorStepper = UIStepper()
        floorStepper.addTarget(self, action: #selector(floorChanged), for: .valueChanged)
        floorStepper.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(floorStepper)

        // Buttons
        let stack = UIStackView()
        stack.axis = .horizontal
        stack.spacing = 8
        stack.distribution = .fillEqually
        stack.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(stack)

        let titles = ["Circle", "Icon", "Line", "Center", "Camera Info"]
        let actions: [Selector] = [
            #selector(addCircle),
            #selector(addIcon),
            #selector(addLine),
            #selector(centerCamera),
            #selector(showCameraInfo)
        ]

        for (i, title) in titles.enumerated() {
            let btn = UIButton(type: .system)
            btn.setTitle(title, for: .normal)
            btn.backgroundColor = .systemBlue
            btn.setTitleColor(.white, for: .normal)
            btn.layer.cornerRadius = 8
            btn.addTarget(self, action: actions[i], for: .touchUpInside)
            stack.addArrangedSubview(btn)
        }

        NSLayoutConstraint.activate([
            floorLabel.topAnchor.constraint(equalTo: view.safeAreaLayoutGuide.topAnchor, constant: 20),
            floorLabel.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            floorStepper.topAnchor.constraint(equalTo: floorLabel.bottomAnchor, constant: 10),
            floorStepper.centerXAnchor.constraint(equalTo: view.centerXAnchor),

            stack.bottomAnchor.constraint(equalTo: view.safeAreaLayoutGuide.bottomAnchor, constant: -20),
            stack.leadingAnchor.constraint(equalTo: view.leadingAnchor, constant: 10),
            stack.trailingAnchor.constraint(equalTo: view.trailingAnchor, constant: -10),
            stack.heightAnchor.constraint(equalToConstant: 44)
        ])
    }

    // MARK: - Floor
    @objc private func floorChanged() {
        let floor = Int(floorStepper.value)
        guard let loc = location, floor < loc.sublocations.count else { return }
        sublocation = loc.sublocations[floor]
        mLocationView.locationWindow.setSublocationId(sublocation!.id)
        floorLabel.text = "Floor: \(floor)"
    }

    // MARK: - Map objects
    @objc private func addCircle() {
        guard let sub = sublocation else { return }
        let circle = mLocationView.locationWindow.addCircleMapObject()
        _ = circle?.setInteractive(true)
        let locationPoint = NCLocationPoint(point: NCPoint(x: sub.width / 2, y: sub.height / 2), locationId: sub.location, sublocationId: sub.id)
        _ = circle?.setPosition(sub.local(toGlobal: locationPoint), sublocationId: NSNumber(value: sub.id))
        _ = circle?.setRadius(25)
        _ = circle?.setColor(UIColor(red: 0, green: 0, blue: 1, alpha: 0.5))
    }

    @objc private func addIcon() {
        guard let sub = sublocation else { return }
        let icon = mLocationView.locationWindow.addIconMapObject()
        let point = NCLocationPoint(
            point: NCPoint(x: sub.width/3, y: sub.height/3),
            locationId: sub.location, sublocationId: sub.id
        )
        let locationPoint = NCLocationPoint(point: point.point, locationId: sub.location, sublocationId: sub.id)
        _ = icon?.setPosition(sub.local(toGlobal: locationPoint), sublocationId: NSNumber(value: sub.id))
        _ = icon?.setBitmap(UIImage(systemName: "mappin.circle.fill"))
        _ = icon?.setSize(32, height: 32)
    }

    @objc private func addLine() {
        guard let sub = sublocation else { return }
        let polyline = mLocationView.locationWindow.addPolylineMapObject()
        let points = [
            NCPoint(x: sub.width/6, y: sub.height/6),
            NCPoint(x: sub.width/2, y: sub.height/2),
            NCPoint(x: sub.width*0.8, y: sub.height*0.7)
        ].map { sub.local(toGlobal: NCLocationPoint(point: $0, locationId: sub.location, sublocationId: sub.id)) }
        let locPolyline = NCLocationPolyline(points: points, sublocationId: NSNumber(value: sub.id))
        _ = polyline?.setPolyLine(locPolyline)
        _ = polyline?.setWidth(3.0)
        _ = polyline?.setColor(UIColor(red: 1, green: 0, blue: 0, alpha: 1))
    }

    // MARK: - Camera
    @objc private func centerCamera() {
        guard let sub = sublocation else { return }
        let point = NCPoint(x: sub.width/2, y: sub.height/2)
        let locationPoint = NCLocationPoint(point: point, locationId: sub.location, sublocationId: sub.id)
        let camera = NCCamera(point: sub.local(toGlobal: locationPoint), zoom: 11.0, rotation: 0.0, tilt: 0.0)
        mLocationView.locationWindow.fly(to: camera, duration: 500, callback: nil)
    }

    @objc private func showCameraInfo() {
        let c = mLocationView.locationWindow.camera
        let msg = "Pos: (\(c.point.latitude), \(c.point.longitude))\nZoom: \(c.zoom)\nRot: \(c.rotation)"
        let alert = UIAlertController(title: "Camera", message: msg, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default))
        present(alert, animated: true)
    }
}

// MARK: - NCLocationListener
extension ViewController: NCLocationListener {
    func onLocationLoaded(_ location: NCLocation?) {
        self.location = location
        floorStepper.maximumValue = Double(location?.sublocations.count ?? 1 - 1)
        floorChanged()
    }
    func onLocationFailed(_ locationId: Int32, error: Error?) { print("Location load failed: \(error?.localizedDescription ?? "unknown")") }
    func onLocationUploaded(_ locationId: Int32) {}
}

// MARK: - Listeners
extension ViewController: NCPickListener {
    func onMapObjectPickComplete(_ r: NCMapObjectPickResult?, screenPosition: CGPoint) {}
    func onMapFeaturePickComplete(_ r: [String : String], screenPosition: CGPoint) {}
}
extension ViewController: NCInputListener {
    func onViewTap(_ point: CGPoint) {}
    func onViewDoubleTap(_ point: CGPoint) {}
    func onViewLongTap(_ point: CGPoint) {}
}
