import UIKit

class TabBarController: UITabBarController {
    
    override func viewDidLoad() {
        
        NavigineApp.initWith(userHash: "0000-0000-0000-0000", serverUrl: "https://api.navigine.com")
        
        let selectedColor = UIColor(red: 62.0 / 255.0, green: 157.0 / 255.0, blue: 202.0 / 255.0, alpha: 1.0)
        
        let normalColor = UIColor(red: 250 / 255.0, green: 250 / 255.0, blue: 250 / 255.0, alpha: 1.0)

        UITabBarItem.appearance().setTitleTextAttributes([NSAttributedString.Key.foregroundColor: selectedColor], for: .selected)
        
        UITabBarItem.appearance().setTitleTextAttributes([NSAttributedString.Key.foregroundColor: normalColor], for: .normal)
        
        tabBar.tintColor = selectedColor
        tabBar.unselectedItemTintColor = normalColor
    }
    
    override func viewWillLayoutSubviews() {
        super.viewWillLayoutSubviews()

        tabBar.frame.size.height = 56
        tabBar.frame.origin.y = view.frame.height - 56
    }
}
