import Foundation

class NavigationViewController: UIViewController {
    @IBOutlet weak var mLocationView: NCDefaultNavigationView!
    @IBOutlet weak var mRecLogs: UIButton!

    var mBottomSheet: FloatingPanelController!
    
    var mLocation: NCLocation!
    
    var mRecording: Bool = false
    
    var mAttached: Bool = false
    
    var mOrientationPointState: Bool = false

    let reuseIdentifier = "subloc"
    
    var subLoc: NCSublocation!

    private var selectedSublocation: NCSublocation? {
        guard let mLocation,
              let selectedId = mLocationView.locationWindow.getSublocationId()?.int32Value else { return subLoc }
        return mLocation.sublocations.first { $0.id == selectedId }
    }
    
    var currentFloor = 0
    
    var mPosition: NCIconMapObject!
    var mCirclePosition: NCCircleMapObject!
    var mAsyncRouteSession: NCRouteSession?
    var mPolylines: [NCDottedPolylineMapObject] = []
    var mRoutePath: NCRoutePath?

    override func viewDidLoad() {
        super.viewDidLoad()
        let viewConfig = NCDefaultNavigationViewConfig.default()
        viewConfig.visibleWidgets = [.followMeButton, .floorSelector]
        mLocationView.viewConfig = viewConfig
        
        NavigineApp.mNavigationManager?.add(self)
        NavigineApp.mZoneManager?.add(self)
        NavigineApp.mRouteManager?.add(self)

        mRecLogs.setTitleColor(UIColor.blue, for: .normal)
        mRecLogs.addTarget(self, action: #selector(recClicked), for: .touchUpInside)

        mLocationView.locationWindow.add(self as NCPickListener)
        mLocationView.locationWindow.add(self as NCInputListener)
        NavigineApp.mLocationManager?.add(self)
        
        NavigineApp.mMeasurementManager?.addWifiGenerator("C83A353BFF20", timeout: 1000, rssiMin: -75, rssiMax: -55)
        
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
}

extension NavigationViewController : NCInputListener {
    func onViewTap(_ screenPoint: CGPoint) {
        mLocationView.locationWindow.pickMapObject(at: screenPoint)
        mLocationView.locationWindow.pickMapFeature(at: screenPoint)
    }
    
    func onViewDoubleTap(_ screenPoint: CGPoint) {}
    
    func onViewLongTap(_ screenPoint: CGPoint) {

        guard let sublocation = selectedSublocation else { return }
        let point = sublocation.global(toLocal: mLocationView.locationWindow.screenPosition(toGlobal: screenPoint))
        
        if let asyncRouteSession = mAsyncRouteSession {
            NavigineApp.mAsyncRouteManager?.cancel(asyncRouteSession)
        }
        let options =  NCRouteOptions(smoothRadius: 0, maxProjectionDistance: 3, maxAdvance: 2)
        mAsyncRouteSession = NavigineApp.mAsyncRouteManager?.createRouteSession(point, routeOptions: options)
        mAsyncRouteSession?.add(self)
    }
}

extension NavigationViewController: NCPickListener {
    func onMapFeaturePickComplete(_ mapFeaturePickResult: [String : String], screenPosition: CGPoint) {
        
    }
    
    func onMapObjectPickComplete(_ mapObjectPickResult: NCMapObjectPickResult?, screenPosition: CGPoint) {
        
    }
}

extension NavigationViewController {
    func setupFloor(_ floor: Int) {
        currentFloor = floor
        subLoc = mLocation?.sublocations[floor]
        mLocationView.locationWindow.setSublocationId(subLoc.id)
        view.layoutIfNeeded()
    }
}

extension NavigationViewController: NCLocationListener {
    
    func onLocationFailed(_ locationId: Int32, error: Error?) { }

    func onLocationUploaded(_ locationId: Int32) { }
    
    func onLocationLoaded(_ location: NCLocation?) {
        guard let location else { return }
        if mLocation == nil || mLocation?.id != location.id {
            currentFloor = 0
            mLocation = location
            generateBeaconsIfNeeded()
            mCirclePosition = mLocationView.locationWindow.addCircleMapObject();
            mCirclePosition.setColor(UIColor(red: 0.5, green: 0, blue: 0, alpha: 1))
            mCirclePosition.setRadius(5)
            
            
            setupFloor(currentFloor)
            
        }
    }
    
}

private extension NavigationViewController {
    func generateBeaconsIfNeeded() {
        NavigineApp.mMeasurementManager?.addBeaconGenerator(
            "F7826DA6-4FA2-4E98-8024-BC5B71E0893E",
            major: 11223,
            minor: 1,
            power: 32,
            timeout: 100,
            rssiMin: -89,
            rssiMax: -55
        )
        NavigineApp.mMeasurementManager?.addBeaconGenerator(
            "F7826DA6-4FA2-4E98-8024-BC5B71E0893E",
            major: 22334,
            minor: 2,
            power: 100,
            timeout: 100,
            rssiMin: -89,
            rssiMax: -55
        )
    }
}

extension NavigationViewController: NCRouteListener {
    func onPathsUpdated(_ paths: [NCRoutePath]) {
        guard let path = paths.first else { return }
        for polyline in mPolylines {
            mLocationView.locationWindow.remove(polyline)
        }
        mPolylines.removeAll()
        drawNewPath(path: path)
        
    }
}

extension NavigationViewController: NCPositionListener {
    func onPositionUpdated(_ position: NCPosition) {
    }

    func onPositionError(_ error: Error?) {
    }
}

extension NavigationViewController: NCZoneListener {
    func onZoneEvent(_ zoneEvent: NCZoneEvent) {
        
    }
    
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

extension NavigationViewController: NCAsyncRouteListener {
    func onRouteChanged(_ status: NCRouteStatus, currentPath: NCRoutePath?) {
        switch status {
            
        case .newRoute:
            guard let path = currentPath else { return }
            for polyline in mPolylines {
                if polyline.isValid {
                    mLocationView.locationWindow.remove(polyline)
                }
            }
            mPolylines.removeAll()
            mRoutePath = path
            
        case .missingRoute:
            print("No route")
        case .missingPosition:
            print("Missing user position")
        case .missingProjection:
            print("Current position is off the route graph")
        default:
            break
        }
    }
    
    
    
    func onRouteAdvanced(_ distance: Float, point: NCLocationPoint) {
        let locationPoint = NCLocationPoint.init(point: point.point, locationId: point.locationId, sublocationId: point.sublocationId)
        
        for polyline in mPolylines {
            if polyline.isValid {
                mLocationView.locationWindow.remove(polyline)
            }
        }
        mPolylines.removeAll()
        
        let paths = mRoutePath?.tail(distance)
        if let drawingPath = paths {
            drawNewPath(path: drawingPath)
            if drawingPath.length <= 1 {
                finishRoute()
            }
        }
        
        guard let currentPath = paths, currentPath.nodes().count > 0, let event = extractEvent(from: currentPath)  else { return }
        print("\(event)")
    }
    
    func extractEvent(from path: NCRoutePath) -> String? {
        let nodes = path.nodes()
        
        guard
            let firstNodeWithEvent = nodes.first(where: { !$0.events.isEmpty }),
            let event = firstNodeWithEvent.events.first
        else {
            return nil
        }
        
        let distance = Int(firstNodeWithEvent.distance.rounded())
        
        switch event.type {
            
        case .TURNEVENT:
            guard let turnEvent = event.turnEvent else { return nil }
            
            switch turnEvent.type {
            case .LEFTSLIGHT:
                return "Turn slightly left after \(distance) meters"
                
            case .LEFTNORMAL:
                return "Turn left after \(distance) meters"
                
            case .LEFTSHARP:
                return "Turn sharply left after \(distance) meters"
                
            case .RIGHTSLIGHT:
                return "Turn slightly right after \(distance) meters"
                
            case .RIGHTNORMAL:
                return "Turn right after \(distance) meters"
                
            case .RIGHTSHARP:
                return "Turn sharply right after \(distance) meters"
                
            case .COMPLETE:
                return "Continue to the destination"
                
            @unknown default:
                return nil
            }
            
        case .TRANSITIONENTRYEVENT:
            guard let transitionEntryEvent = event.transitionEntryEvent else { return nil }
            
            return "Change floor after \(distance) meters"
            
        case .TRANSITIONEXITEVENT:
            guard let transitionExitEvent = event.transitionExitEvent else { return nil }
            
            return "Exit to the outside after \(distance) meters"
            
        case .TARGETREACHEDEVENT:
            return "You have arrived at your destination"
            
        @unknown default:
            return nil
        }
    }
    
    func finishRoute() {
        mRoutePath = nil
        mAsyncRouteSession?.remove(self)
        NavigineApp.mAsyncRouteManager?.cancel(mAsyncRouteSession)
        
        for polilyne in mPolylines {
            polilyne.setVisible(false)
            mLocationView.locationWindow.remove(polilyne)
        }
        mPolylines.removeAll()
        
    }
    
    func drawNewPath(path: NCRoutePath) {
        guard let location = mLocation else { return }
        for segment in globalRouteSegments(for: path, in: location) where segment.points.count > 1 {
            let polyline = createNewPolyline()
            let sublocationId: NSNumber? = mLocationView.locationWindow.getOperatingMode() == .indoorOnly
                ? NSNumber(value: segment.sublocationId)
                : nil
            polyline.setPolyLine(NCLocationPolyline(points: segment.points, sublocationId: sublocationId))
            polyline.setVisible(true)
            mPolylines.append(polyline)
        }
        
    }
    
    func createNewPolyline() -> NCDottedPolylineMapObject {
        let polyline = mLocationView.locationWindow.addDottedPolylineMapObject()!
        polyline.setColor(UIColor(red: 0.298, green: 0.851, blue: 0.392, alpha: 1))
        polyline.setVisible(false)
        polyline.setPlacement(.SPACED)
        polyline.setPlacementMinRatio(0)
        polyline.setPlacementSpacing(8)
        polyline.setSize(8, height: 8)
        polyline.setCollisionEnabled(false)
        return polyline
    }
    
}
