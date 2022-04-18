import Foundation

class NavigationController: UIViewController {
    
    @IBOutlet weak var mLocationView: NCLocationView!
    @IBOutlet weak var mCollectionView: UICollectionView!
    @IBOutlet weak var mLevelsButton: UIButton!
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
        NavigineApp.mLocationManager?.add(self)
        NavigineApp.mNavigationManager?.add(self)
        NavigineApp.mZoneManager?.add(self)
        NavigineApp.mRouteManager?.add(self)

        mRecLogs.setTitleColor(UIColor.blue, for: .normal)
        mLevelsButton.addTarget(self, action: #selector(levelsClicked), for: .touchUpInside)
        mRecLogs.addTarget(self, action: #selector(recClicked), for: .touchUpInside)

        mLocationView.gestureDelegate = self
        
        mSublocationPicker = SublocationPicker(frame: CGRect(x: 0, y: 0, width: 180, height: 22))
        
        mSublocationPicker!.sublocationPickerDelegate = self
        navigationItem.titleView = mSublocationPicker
        
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
        
        mZoomInBtn.isHidden = true
        mZoomOutBtn.isHidden = true
        
        mPosition = mLocationView.addIconMapObject()
        mPosition.setBitmap(UIImage(named: "UserLocation"))
        mPosition.setSize(Float(30), height: Float(30))
        mPosition.setVisible(false)
        
        mPolyline = mLocationView.addPolylineMapObject()
        mPolyline.setColor(0.0, green: 0.5, blue: 0.5, alpha: 1)
        mPolyline.setWidth(Float(0.1))
        mPolyline.setVisible(false)
    }
    
    
    
    @objc func levelsClicked(_ sender: AnyObject?) {
        mCollectionView.isHidden = !mCollectionView.isHidden
//        mZoomInBtn.isHidden = !mZoomInBtn.isHidden
//        mZoomOutBtn.isHidden = !mZoomOutBtn.isHidden
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
//        mLocationView.zoomFactor = zoomFactor * 2
    }
    
    
    @IBAction func zoomOut(_ sender: Any) {
        let zoomFactor = mLocationView.zoomFactor
//        mLocationView.zoomFactor = zoomFactor / 2
    }
}

extension NavigationController : NCGestureRecognizerDelegate {
    func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeSingleTapGesture location: CGPoint) {
        view.pickMapObject(at: location)
    }
    
    func locationView(_ view: NCLocationView!, recognizer: UIGestureRecognizer!, didRecognizeLongPressGesture location: CGPoint) {
        NavigineApp.mRouteManager?.clearTargets()

        let point = NCLocationPoint(point: NCPoint.init(x: 0, y: 0), locationId: mLocation.id , sublocationId: subLoc.id)
        NavigineApp.mRouteManager?.setTarget(point);
    }
}

extension NavigationController: NCPickListener {
    func onMapFeaturePickComplete(_ mapFeaturePickResult: [String : String], screenPosition: CGPoint) {
        
    }
    
    func onMapObjectPickComplete(_ mapObjectPickResult: NCMapObjectPickResult?, screenPosition: CGPoint) {
        
    }
}

extension NavigationController: SublocationPickerDelegate {
    func setupFloor(_ floor: Int) {
        currentFloor = floor
        subLoc = mLocation?.sublocations[floor]
        mLocationView.setSublocationId(subLoc.id)
        
        mLocationView.maxZoomFactor = mLocationView.frame.width * 20 / CGFloat(subLoc.width)
        mLocationView.zoomFactor = mLocationView.frame.width / 20 / CGFloat(subLoc.width)
        
        view.layoutIfNeeded()
    }
    
    
}

extension NavigationController: UICollectionViewDataSource, UICollectionViewDelegateFlowLayout {
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        self.mSublocationsList.count
    }
    
    func collectionView(_ collectionView: UICollectionView, cellForItemAt indexPath: IndexPath) -> UICollectionViewCell {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: reuseIdentifier, for: indexPath as IndexPath) as! MyCollectionViewCell
        
        cell.mLabel.text = self.mSublocationsList[indexPath.item].name
//        cell.backgroundColor = UIColor.white
        cell.contentView.backgroundColor = .white
        cell.contentView.layer.cornerRadius = 6
        cell.contentView.layer.borderWidth = 0.5
        cell.contentView.layer.borderColor = UIColor.black.cgColor
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath) {
        if subLoc != mSublocationsList[indexPath.row] {
            subLoc = mSublocationsList[indexPath.row]
            mLocationView.setSublocationId(subLoc.id)
            
            mLocationView.maxZoomFactor = mLocationView.frame.width * 2 / CGFloat(subLoc.width)
            mLocationView.zoomFactor = mLocationView.frame.width / CGFloat(subLoc.width)
            
            collectionView.isHidden = true
            mZoomInBtn.isHidden = false
            mZoomOutBtn.isHidden = false
        }
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAt indexPath: IndexPath) -> CGSize {
        let yourWidth = (collectionView.bounds.width - 30) / 2.0
        let yourHeight = (collectionView.bounds.height - 20 - mLevelsButton.frame.size.height) / 4.0
        
        return CGSize(width: yourWidth, height: yourHeight)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, insetForSectionAt section: Int) -> UIEdgeInsets {
        return UIEdgeInsets.init(top: mLevelsButton.frame.size.height, left: 10, bottom: 10, right: 10)
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumInteritemSpacingForSectionAt section: Int) -> CGFloat {
        return 5
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAt section: Int) -> CGFloat {
        return 5
    }
}

extension NavigationController: NCLocationListener {
    func onDownloadProgress(_ received: Int32, total: Int32) { }
    
    func onLocationLoaded(_ location: NCLocation?) {
        currentFloor = 0
        self.mSublocationsList.removeAll()
        mLocation = location
        mCirclePosition = mLocationView.addCircleMapObject();
        mCirclePosition.setColor(0.5, green: 0, blue: 0, alpha: 1)
        mCirclePosition.setRadius(5)
        
        mSublocationPicker?.setLocation(location!)
        mSublocationPicker?.updateUI(currentFloor)
        
        for subloc in location!.sublocations {
            self.mSublocationsList.append(subloc)
        }
//        self.mCollectionView.isHidden = false
//        self.mCollectionView.reloadData()
    }
    
    func onLocationFailed(_ error: Error?) {
        
    }
}

extension NavigationController: NCRouteListener {
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

extension NavigationController: NCPositionListener {
    func onPositionUpdated(_ position: NCPosition) {
        if (mPosition != nil) {
            let locationPoint = NCLocationPoint.init(point: position.point, locationId: position.locationId, sublocationId: position.sublocationId)
            mPosition.setPositionAnimated(locationPoint, duration: 1.0, type: NCAnimationType.cubic)
            mPosition.setVisible(true)
        }
    }

    func onPositionError(_ error: Error?) {
        mCirclePosition.setVisible(false)
    }
}

extension NavigationController: NCZoneListener {
    func onEnter(_ zone: NCZone?) {
        print("OnEnter zone \(String(describing: zone?.name))")
    }
    
    func onLeave(_ zone: NCZone?) {
        print("onLeave zone \(String(describing: zone?.name))")
    }
    
    
}

extension NavigationController: FloatingPanelControllerDelegate {
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

