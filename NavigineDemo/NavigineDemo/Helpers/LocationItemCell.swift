import Foundation
import UIKit

class LocationItemCell: UITableViewCell {
    
    @IBOutlet weak var nameView: UILabel!
    @IBOutlet weak var versionView: UILabel!
    @IBOutlet weak var progressBar: CircularLoaderView!
    
    override func prepareForReuse() {
        super.prepareForReuse()
        self.progressBar.isHidden = false
    }
}
