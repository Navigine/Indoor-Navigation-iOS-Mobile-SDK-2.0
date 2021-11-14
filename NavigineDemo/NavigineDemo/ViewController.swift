import UIKit

class ViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {
    
    @IBOutlet weak var mTableView: UITableView!
    
    var mLocationsList: [String] = []
    
    var mNavigineSdk: NCNavigineSdk?
    var mLocationListManager: NCLocationListManager?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        mNavigineSdk = NCNavigineSdk.createInstance("4EE6-9A3F-F126-5FE6", server: "https://api.navigine.com")
        
        mLocationListManager = mNavigineSdk?.getLocationListManager()
        
        mLocationListManager?.add(self)
        
        self.mTableView.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.mLocationsList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell:UITableViewCell = self.mTableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath as IndexPath)

        cell.textLabel?.text = self.mLocationsList[indexPath.row]

        return cell
    }
}

extension ViewController: NCLocationListListener {
    func onLocationListLoaded(_ locationInfos: [NSNumber : NCLocationInfo]) {
        self.mLocationsList.removeAll()
        for el in locationInfos {
            self.mLocationsList.append(el.value.name)
        }
        self.mTableView.reloadData()
    }
    
    func onLocationListFailed(_ error: Error?) {
        
    }
}
