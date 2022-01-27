import Foundation

class ProfileController: UIViewController {
    
    @IBOutlet weak var mLogsTable: UITableView!
    @IBOutlet weak var mUpdate: UIButton!
    
    var mLogsList: [String] = []
    
    override func viewDidLoad() {
        mLogsList.removeAll()
        for el in (NavigineApp.mResourceManager?.getLogsList())! {
            mLogsList.append(el)
        }
        self.mLogsTable.reloadData()
        
        mUpdate.addTarget(self, action: #selector(update), for: .touchUpInside)
    }
    
    @objc func update(_ sender: AnyObject?) {
        mLogsList.removeAll()
        for el in (NavigineApp.mResourceManager?.getLogsList())! {
            mLogsList.append(el)
        }
        self.mLogsTable.reloadData()
    }
}

extension ProfileController: UITableViewDelegate, UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.mLogsList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if let cell = tableView.dequeueReusableCell(withIdentifier:"logs", for: indexPath) as? LogsItemCell {
            cell.mLogName.text = self.mLogsList[indexPath.row]
                        
            return cell
        }
        return UITableViewCell()
    }
    
    func tableView(_ tableView: UITableView, viewForFooterInSection section: Int) -> UIView? {
        return UIView()
    }
    
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        NavigineApp.mResourceManager?.uploadLogFile(self.mLogsList[indexPath.row], listener: self)
    }
}

extension ProfileController : NCResourceUploadListener {
    func onUploaded() {
        print("success")
    }

    func onFailed(_ error: Error?) {
        print("fail \(String(describing: error))")
    }
}
