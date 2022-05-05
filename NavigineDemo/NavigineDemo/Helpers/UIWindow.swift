//
//  UIWindow.swift
//  Navigine
//
//  Created by Alexander Terletskiy on 22.04.2020.
//  Copyright © 2020 Navigine. All rights reserved.
//

import Foundation
import UIKit

extension UIWindow {
  func visibleViewController() -> UIViewController? {
    let rootViewController = self.rootViewController
    return UIWindow.getVisibleViewController(from: rootViewController)
  }

  class func getVisibleViewController(from vc: UIViewController?) -> UIViewController? {
    if (vc is UINavigationController) {
      return UIWindow.getVisibleViewController(from: (vc as? UINavigationController)?.visibleViewController)
    } else if (vc is UITabBarController) {
      return UIWindow.getVisibleViewController(from: (vc as? UITabBarController)?.selectedViewController)
    } else {
      if vc?.presentedViewController != nil {
        return UIWindow.getVisibleViewController(from: vc?.presentedViewController)
      } else {
        return vc
      }
    }
  }
}
