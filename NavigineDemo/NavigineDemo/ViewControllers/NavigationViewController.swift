import Foundation

class NavigationViewController: UIViewController {
    
    @IBOutlet weak var mLocationView: NCLocationView!
    @IBOutlet weak var mRecLogs: UIButton!
    
    @IBOutlet weak var mZoomInBtn: UIButton!
    @IBOutlet weak var mZoomOutBtn: UIButton!

    var mBottomSheet: FloatingPanelController!
    
    var mLocation: NCLocation!
    
    var mRecording: Bool = false
    
    var mAttached: Bool = false
    
    let reuseIdentifier = "subloc"
    
    var subLoc: NCSublocation!
    
    var mSublocationsList: [NCSublocation] = []
    
    var mSublocationPicker: SublocationPicker?
    
    var currentFloor = 0
    
    var mPosition: NCIconMapObject!
    var mCirclePosition: NCCircleMapObject!
    var mPolyline: NCPolylineMapObject!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        NavigineApp.mNavigationManager?.add(self)
        NavigineApp.mZoneManager?.add(self)
        NavigineApp.mRouteManager?.add(self)

        mRecLogs.setTitleColor(UIColor.blue, for: .normal)
        mRecLogs.addTarget(self, action: #selector(recClicked), for: .touchUpInside)

        mLocationView.gestureDelegate = self
        
        mSublocationPicker = SublocationPicker(frame: CGRect(x: 0, y: 0, width: 180, height: 22))
        mSublocationPicker!.sublocationPickerDelegate = self
        self.navigationItem.titleView = mSublocationPicker
        navigationController?.navigationBar.isHidden = false
        navigationController?.navigationBar.isUserInteractionEnabled = true
        //.titleView?.isUserInteractionEnabled = true
        NavigineApp.mLocationManager?.add(self)
        
//        NavigineApp.mMeasurementManager?.addWifiGenerator("C83A353BFF20", timeout: 1000, rssiMin: -75, rssiMax: -55)
//
//        NavigineApp.mMeasurementManager?.addBeaconGenerator(
//            "F7826DA6-4FA2-4E98-8024-BC5B71E0893E",
//            major: 1,
//            minor: 1,
//            power: 32, timeout: 100, rssiMin: -89, rssiMax: -55);
//
//        NavigineApp.mMeasurementManager?.addBeaconGenerator(
//            "00A10979-B448-3314-2059-DC5DEB6A1005",
//            major: 2968,
//            minor: 26457,
//            power: 32, timeout: 100, rssiMin: -89, rssiMax: -55);
        
        mPosition = mLocationView.addIconMapObject()
        mPosition.setBitmap(UIImage(named: "UserLocation"))
        mPosition.setSize(Float(30), height: Float(30))
        mPosition.setVisible(false)
        mPosition.setStyle("{ order: 1, collide: false}")
        
        mPolyline = mLocationView.addPolylineMapObject()
        mPolyline.setColor(0.0, green: 0.5, blue: 0.5, alpha: 1)
        mPolyline.setWidth(4)
        mPolyline.setVisible(false)
        mPolyline.setStyle("{style: 'points', placement_min_length_ratio: 0, placement_spacing: 8px, size: [8px, 8px], placement: 'spaced', collide: false}")
    }
    
    override func viewWillAppear(_ animated: Bool) {
      super.viewWillAppear(animated)
      setNavigationViewColor(color: UIColor(displayP3Red: 29/255.0, green: 51/255.0, blue: 79/255.0, alpha: 1.0), textColor: .white)
    }
    
    @objc func recClicked(_ sender: AnyObject?) {
        mAttached = !mAttached;
        if !mRecording {
            mRecLogs.setTitle("Stop", for: .normal)
            mRecLogs.setTitleColor(UIColor.red, for: .normal)
            NavigineApp.mNavigationManager?.startLogRecording()
        } else {
            mRecLogs.setTitle("Rec", for: .normal)
            mRecLogs.setTitleColor(UIColor.blue, for: .normal)
            NavigineApp.mNavigationManager?.stopLogRecording()
        }
        mRecording = !mRecording
    }
    
    @IBAction func zoomIn(_ sender: Any) {
        let zoomFactor = mLocationView.zoomFactor
        mLocationView.zoomFactor = zoomFactor * 2
    }
    
    
    @IBAction func zoomOut(_ sender: Any) {
        let zoomFactor = mLocationView.zoomFactor
        mLocationView.zoomFactor = zoomFactor / 2
    }
}

extension NavigationViewController : NCGestureRecognizerDelegate {
    func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeSingleTapGesture location: CGPoint) {
        view.pickMapObject(at: location)
    }
    
    func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeLongPressGesture location: CGPoint) {
        NavigineApp.mRouteManager?.clearTargets()

        let point = view.screenPosition(toMeters: location)
        let locPoint = NCLocationPoint(point: point, locationId: mLocation.id , sublocationId: subLoc.id)
        NavigineApp.mRouteManager?.setTarget(locPoint)
    }
}

extension NavigationViewController: NCPickListener {
    func onMapFeaturePickComplete(_ mapFeaturePickResult: [String : String], screenPosition: CGPoint) {
        
    }
    
    func onMapObjectPickComplete(_ mapObjectPickResult: NCMapObjectPickResult?, screenPosition: CGPoint) {
        
    }
}

extension NavigationViewController: SublocationPickerDelegate {
    func setupFloor(_ floor: Int) {
        currentFloor = floor
        subLoc = mLocation?.sublocations[floor]
        mLocationView.setSublocationId(subLoc.id)
        
        mLocationView.maxZoomFactor = mLocationView.frame.width * 20 / CGFloat(subLoc.width)
        mLocationView.zoomFactor = mLocationView.frame.width / 20 / CGFloat(subLoc.width)
        
        view.layoutIfNeeded()
    }
    
    
}

extension NavigationViewController: NCLocationListener {
    
    func onLocationFailed(_ locationId: Int32, error: Error?) { }

    func onLocationUploaded(_ locationId: Int32) { }
    
    func onLocationLoaded(_ location: NCLocation?) {
        if mLocation == nil || mLocation?.id != location?.id {
            currentFloor = 0
            self.mSublocationsList.removeAll()
            mLocation = location
            mCirclePosition = mLocationView.addCircleMapObject();
            mCirclePosition.setColor(0.5, green: 0, blue: 0, alpha: 1)
            mCirclePosition.setRadius(5)
            
            mSublocationPicker?.setLocation(location!)
            mSublocationPicker?.updateUI(currentFloor)
            
            setupFloor(currentFloor)
            
            for subloc in location!.sublocations {
                self.mSublocationsList.append(subloc)
            }
        }
    }
    
}

extension NavigationViewController: NCRouteListener {
    func onPathsUpdated(_ paths: [NCRoutePath]) {
        var points: [NCPoint] = []
        for point in paths[0].points {
            points.append(point.point)
        }

        let polyline = NCLocationPolyline.init(polyline: NCPolyline.init(points: points), locationId: subLoc.location, sublocationId: subLoc.id)
        mPolyline.setPolyLine(polyline)
        mPolyline.setVisible(true)
    }
}

extension NavigationViewController: NCPositionListener {
    func onPositionUpdated(_ position: NCPosition) {
        if (mPosition != nil && position.locationPoint != nil) {
            mPosition.setPositionAnimated(position.locationPoint!, duration: 1.0, type: NCAnimationType.cubic)
            mPosition.setVisible(true)
        }
    }

    func onPositionError(_ error: Error?) {
        if mCirclePosition != nil {
            mCirclePosition.setVisible(false)
        }
    }
}

extension NavigationViewController: NCZoneListener {
    func onEnter(_ zone: NCZone?) {
        print("OnEnter zone \(String(describing: zone?.name))")
    }
    
    func onLeave(_ zone: NCZone?) {
        print("onLeave zone \(String(describing: zone?.name))")
    }
    
    
}

extension NavigationViewController: FloatingPanelControllerDelegate {
    func addMainPanel(with contentVC: UIViewController) {
        
        let oldBottomSheet = mBottomSheet
        
        mBottomSheet = FloatingPanelController()
        mBottomSheet.set(contentViewController: contentVC)
        
        mBottomSheet.contentInsetAdjustmentBehavior = .always
        
        mBottomSheet.surfaceView.cornerRadius = 6.0
        mBottomSheet.surfaceView.shadowHidden = false
        
        mBottomSheet.isRemovalInteractionEnabled = true
        mBottomSheet.delegate = self
        
        let backdropTapGesture = UITapGestureRecognizer(target: self, action: #selector(handleBackdrop(tapGesture:)))
        mBottomSheet.backdropView.addGestureRecognizer(backdropTapGesture)
        
        if let oldBottomSheet = oldBottomSheet {
            oldBottomSheet.removePanelFromParent(animated: true, completion: {
                self.mBottomSheet.addPanel(toParent: self, belowView: nil, animated: true)
            })
        } else {
            mBottomSheet.addPanel(toParent: self, belowView: nil, animated: true)
        }
    }
    
    
    @objc
    func handleBackdrop(tapGesture: UITapGestureRecognizer) {
        switch tapGesture.view {
        case mBottomSheet.backdropView:
            mBottomSheet.hide(animated: true, completion: nil)
        default:
            break
        }
    }
    
    func floatingPanel(_ vc: FloatingPanelController, contentOffsetForPinning trackedScrollView: UIScrollView) -> CGPoint {
        return CGPoint(x: 0.0, y: 0.0 - trackedScrollView.contentInset.top)
    }
    
    func floatingPanel(_ vc: FloatingPanelController, layoutFor newCollection: UITraitCollection) -> FloatingPanelLayout? {
        guard let viewController = vc.contentViewController else {
            return RemovablePanelLayout()
        }
        
        if (viewController.isKind(of: VenueDetailsViewController.self)) {
            return VenueDetailsViewController.VenueDetailsSheetLayout()
        }
        
        return RemovablePanelLayout()
    }
    
    func floatingPanel(_ vc: FloatingPanelController, shouldRecognizeSimultaneouslyWith gestureRecognizer: UIGestureRecognizer) -> Bool {
        return true
    }
    
    func floatingPanelDidEndDraggingToRemove(_ vc: FloatingPanelController, withVelocity velocity: CGPoint) {
        mBottomSheet.removePanelFromParent(animated: true)
        mBottomSheet = nil
        guard let viewController = vc.contentViewController else {
            return
        }
    }
    
    func floatingPanelDidEndDragging(_ vc: FloatingPanelController, withVelocity velocity: CGPoint, targetPosition: FloatingPanelPosition)  {
        
    }
    
    func floatingPanelDidMove(_ vc: FloatingPanelController) {
        //    guard let viewController = vc.contentViewController else {
        //      return
        //    }
        //    if (viewController.isKind(of: VenueDetailsViewController.self)) {
        //      let controller = viewController as! VenueDetailsViewController
        //      controller.setPosition(position: targetPosition)
        //    }
    }
    
    func floatingPanelDidEndRemove(_ vc: FloatingPanelController) {
        //        switch vc {
        //        case settingsPanelVC:
        //            settingsPanelVC = nil
        //        default:
        //            break
        //        }
    }
}

/**
 - Attention: `FloatingPanelLayout` must not be applied by the parent view
 controller of a floating panel. But here `SampleListViewController` adopts it
 purposely to check if the library prints an appropriate warning.
 */
class RemovablePanelLayout: FloatingPanelIntrinsicLayout {
    var supportedPositions: Set<FloatingPanelPosition> {
        return [.half]
    }
    var initialPosition: FloatingPanelPosition {
        return .half
    }
    var topInteractionBuffer: CGFloat {
        return 30.0
    }
    
    func insetFor(position: FloatingPanelPosition) -> CGFloat? {
        switch position {
        case .half: return 200.0
        default: return nil
        }
    }
}

