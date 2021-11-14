import UIKit

class VenueDetailsViewController: UIViewController {
  public var didDismiss: ((VenueDetailsViewController) -> Void)?
  
  @IBOutlet weak var mVenueTitle: UILabel!
  @IBOutlet weak var mVenueContent: UILabel!
  @IBOutlet weak var mVenueImage: UIImageView!
  @IBOutlet weak var mBottomConstraint: NSLayoutConstraint!
  
  private var mVenue = NCVenue()
      
  override func viewDidLoad() {
    super.viewDidLoad()

    mVenueTitle.text = mVenue.name
    mVenueContent.text = mVenue.descript
    
    mVenueImage.alpha = 0.0
    mBottomConstraint.constant = 224
  }
  
  static func instantiate() -> VenueDetailsViewController {
    return UIStoryboard(name: "Navigation", bundle: nil).instantiateViewController(withIdentifier: "VenueDetailsVC") as! VenueDetailsViewController
  }
  
  func setVenueMapObject(venue: NCVenue) {
    mVenue = venue;
  }

  func setPosition(position: FloatingPanelPosition) {
    DispatchQueue.main.async {
      UIView.animate(withDuration: 0.3, animations: {
        switch position {
          case .full:
            self.mVenueImage.alpha = 1.0
            self.mBottomConstraint.constant = 40
            break
          default:
            self.mVenueImage.alpha = 0.0
            self.mBottomConstraint.constant = 224
        }
      })
    }
  }
  
  @IBAction func closeButtonAction(_ sender: Any) {
    didDismiss!(self)
  }
}

extension VenueDetailsViewController {
  /**
   - Attention: `FloatingPanelLayout` must not be applied by the parent view
   controller of a floating panel. But here `SampleListViewController` adopts it
   purposely to check if the library prints an appropriate warning.
   */
  
  class VenueDetailsSheetLayout: FloatingPanelLayout {
    var supportedPositions: Set<FloatingPanelPosition> {
      return [.full, .half]
    }
    
    public var initialPosition: FloatingPanelPosition {
        return .half
    }

    public func insetFor(position: FloatingPanelPosition) -> CGFloat? {
        switch position {
        case .full: return 18.0
        case .half: return 243.0
        default: return nil
      }
    }
  }
}
