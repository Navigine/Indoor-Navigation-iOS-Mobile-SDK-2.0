//
//  UIViewController.swift
//  NavigineDemo
//
//  Created by Elvira Khabibullina on 19.04.2022.
//  Copyright © 2022 navigine. All rights reserved.
//

import UIKit

extension UIViewController {
    
    func setNavigationViewColor(color: UIColor, textColor: UIColor) {
      if #available(iOS 13.0, *) {
        let appearance = UINavigationBarAppearance()
        appearance.backgroundColor = color
        appearance.titleTextAttributes = [.foregroundColor: textColor]
        appearance.largeTitleTextAttributes = [.foregroundColor: textColor]

        navigationController?.navigationBar.tintColor = textColor
        navigationController?.navigationBar.standardAppearance = appearance
        navigationController?.navigationBar.compactAppearance = appearance
        navigationController?.navigationBar.scrollEdgeAppearance = appearance
      } else {
        // Fallback on earlier versions
      }
    }
}
