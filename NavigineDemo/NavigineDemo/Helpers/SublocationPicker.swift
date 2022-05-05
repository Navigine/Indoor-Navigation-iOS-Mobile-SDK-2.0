//
//  SublocationPicker.swift
//  Navigine
//
//  Created by Alexander Terletskiy on 20.04.2020.
//  Copyright © 2020 Navigine. All rights reserved.
//

import Foundation
import UIKit

enum AnimationConstants {
  static let kAnimationDuration: Float = 0.4
  static let kDefaultSublocationIndex: Float = 0
}

typealias animationBlock = () -> Void

@objc protocol SublocationPickerDelegate: AnyObject {
  func setupFloor(_ floor: Int)
}

struct DelegateFlags {
  var didDoneClicked: Bool
  var didCancelClicked: Bool
}

// TODO: Fix autolayout issues!!!
class SublocationPicker: UITextField, UITextFieldDelegate, UIGestureRecognizerDelegate {

  var delegateFlagsDelegate: DelegateFlags?
  @objc weak var sublocationPickerDelegate: SublocationPickerDelegate?
  private var picker: UIPickerView?
  private var tableView: UITableView?
  /// Selected sublocation index
  var sublocationIndex = 0
  private var blankView: UIView?
  // UI attributes
  private var defaultFont: UIFont?
  private var defaultFontSize = 0
  private var downArrow: UIImageView?
  private let heightForCell = 48
  private var mLocation: NCLocation? = nil
  var cell = "cell"

  override init(frame: CGRect) {
    super.init(frame: frame)
    // Init UI attributes
    defaultFontSize = Int(17.0)
    defaultFont = UIFont(name: "Circe-Regular", size: CGFloat(defaultFontSize))

    // Change color of placeholder to white
    attributedPlaceholder = NSAttributedString(string: sublocationName(at: 0)! /* Default sublocation */, attributes: [
      NSAttributedString.Key.foregroundColor: UIColor.white
    ])
    //     Setup down arrow
    downArrow = UIImageView(image: UIImage(named: "down_arrow"))
    downArrow?.contentMode = UIView.ContentMode.right
    downArrow?.frame.size.height = 8
    downArrow?.frame.size.width = 8
    downArrow?.isHidden = true

    // TODO: Consider self.rightView
    self.rightView = downArrow
    self.rightViewMode = .always

    self.inputView = UIView()
    self.inputAccessoryView = UIView()
    self.tintColor = .white

    // Setup textfield
    self.font = defaultFont
    self.textColor = UIColor.white
    self.textAlignment = .center
    self.delegate = self

    // Setup blank view
    setupBlankView()

    // Configure table view
    setupTableView()
  }

  required init?(coder: NSCoder) {
    fatalError("init(coder:) has not been implemented")
  }

  func setLocation(_ location: NCLocation) {
    mLocation = location
    downArrow?.isHidden = location.sublocations.count == 1
  }

  @objc func updateUI(_ index: Int) {
    sublocationIndex = index
    guard let location = mLocation else {
      return
    }
    self.text = location.sublocations[sublocationIndex].name
    downArrow?.isHidden = location.sublocations.count == 1
    setupTableView()
  }

  func updateArrowPosition() {
    guard let location = mLocation else {
      return
    }
    downArrow?.transform = CGAffineTransform(rotationAngle: (180 * .pi) / 180.0)
    location.sublocations.count > 1 ? (downArrow!.isHidden = false) : (downArrow!.isHidden = true)
  }

  func updateArrowPositionDown() {
    downArrow?.transform = CGAffineTransform(rotationAngle: (360 * .pi) / 1)
  }

  // MARK: - Custom accessors
  func setSublocationPickerDelegate(_ sublocationPickerDelegate: SublocationPickerDelegate?) {
    self.sublocationPickerDelegate = sublocationPickerDelegate
  }

  // MARK: - Disable selection cursor
  override func caretRect(for position: UITextPosition) -> CGRect {
    return CGRect.zero
  }

  override func selectionRects(for range: UITextRange) -> [UITextSelectionRect] {
    return []
  }

  override func canPerformAction(_ action: Selector, withSender sender: Any?) -> Bool {
    if action == #selector(copy(_:)) || action == #selector(selectAll(_:)) || action == #selector(paste(_:)) {
      return false
    }
    return super.canPerformAction(action, withSender: sender)
  }

  // MARK: - UITextFieldDelegate
  func textFieldShouldBeginEditing(_ textField: UITextField) -> Bool {
    guard let location = mLocation else {
      return false
    }
    if location.sublocations.count > 1 {
      return true
    }
    return false
  }

  func textFieldDidBeginEditing(_ textField: UITextField) {
    fade(withAnimation: {
      self.blankView!.alpha = 1
    })
    self.text = "Choose sublocation"
    self.font = UIFont(name: "Circe-Regular", size: 17)
    updateArrowPosition()
  }

  func textFieldDidEndEditing(_ textField: UITextField) {
    guard let location = mLocation else {
      return
    }
    fade(withAnimation: {
      self.blankView!.alpha = 0.0
    })
    self.text = location.sublocations[sublocationIndex].name
    updateArrowPositionDown()
  }

  // MARK: - UIGestureRecognizer
  func gestureRecognizer(_ gestureRecognizer: UIGestureRecognizer,
                         shouldReceive touch: UITouch) -> Bool {
    return (touch.view == blankView)
  }

  // MARK: - BlankView
  func fade(withAnimation animations: @escaping animationBlock ) {
    UIView.transition(with: blankView!, duration: TimeInterval(AnimationConstants.kAnimationDuration),
                      options: .transitionCrossDissolve, animations: animations)
  }

  @objc func tapByBlankView() {
    fade(withAnimation: {
      self.blankView!.alpha = 0.0
    })
    resignFirstResponder()
  }

  // Disable all swipes by blank view
  @objc func swipe(byBlankView recognizer: UIPanGestureRecognizer?) {
    recognizer?.isEnabled = true
  }

  func setupBlankView() {
    if (blankView != nil) {
      blankView?.removeFromSuperview()
    }
    let screenSize = UIScreen.main.bounds.size
    blankView = UIView(frame: CGRect(x: 0, y: 0, width: screenSize.width, height: screenSize.height))
    blankView!.translatesAutoresizingMaskIntoConstraints = false
    blankView!.backgroundColor = UIColor(red: 148/255, green:  158/255, blue: 168/255, alpha:  0.8)
    blankView!.alpha = 0.0
    let tapGesture = UITapGestureRecognizer(target: self, action: #selector(tapByBlankView))
    tapGesture.delegate = self
    let panGesture = UIPanGestureRecognizer(target: self, action: #selector(swipe(byBlankView:)))

    blankView!.addGestureRecognizer(tapGesture)
    blankView!.addGestureRecognizer(panGesture)

    let vc = UIApplication.shared.keyWindow?.visibleViewController()
    vc?.view.addSubview(blankView!)
  }

  // MARK: - Private
  func sublocationName(at index: Int) -> String? {
    guard let location = mLocation else {
      return ""
    }
    var sublocationName = ""
    if index < location.sublocations.count {
      sublocationName = location.sublocations[index].name
    } else {
      print("Subl index out of bounds!")
    }
    return sublocationName
  }

  // Setup UITableView
  func setupTableView() {
    if (tableView != nil) {
      tableView!.removeFromSuperview()
    }
    guard let location = mLocation else {
      return
    }
    let tableWidth = UIScreen.main.bounds.size.width
    var tableHeight = 5 * heightForCell
    if location.sublocations.count < 5 {
      tableHeight = location.sublocations.count * heightForCell
    }
    tableView = UITableView(frame: CGRect(x: 0, y: 88, width: Int(tableWidth), height: tableHeight))
    tableView?.translatesAutoresizingMaskIntoConstraints = true
    tableView?.register(UITableViewCell.self, forCellReuseIdentifier: "cell")
    tableView?.delegate = self
    tableView?.dataSource = self
    tableView?.backgroundColor = UIColor(red: 21/255, green: 45/255, blue: 71/255, alpha: 1)
    self.blankView?.addSubview(tableView!)
  }

  class func topViewController() -> UIViewController? {
    return self.topViewController(withRootViewController: UIApplication.shared.delegate?.window?!.rootViewController)
  }

  class func topViewController(withRootViewController rootViewController: UIViewController?) -> UIViewController? {
    if (rootViewController is UITabBarController) {
      let tabBarController = rootViewController as? UITabBarController
      return self.topViewController(withRootViewController: tabBarController?.selectedViewController)
    } else if (rootViewController is UINavigationController) {
      let navigationController = rootViewController as? UINavigationController
      return self.topViewController(withRootViewController: navigationController?.visibleViewController)
    } else if rootViewController?.presentedViewController != nil {
      let presentedViewController = rootViewController?.presentedViewController
      return self.topViewController(withRootViewController: presentedViewController)
    } else {
      return rootViewController
    }
  }
}

extension SublocationPicker: UITableViewDataSource, UITableViewDelegate {

  func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
    guard let location = mLocation else {
      return 0
    }
    return location.sublocations.count
  }

  func numberOfSections(in tableView: UITableView) -> Int {
    return 1
  }

  func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
    let cell = tableView.dequeueReusableCell(withIdentifier: "cell", for: indexPath)
    guard let location = mLocation else {
      return cell
    }
    cell.textLabel?.text = location.sublocations[indexPath.row].name
    cell.textLabel?.textAlignment = .center
    cell.textLabel?.textColor = .white
    cell.selectionStyle = .none
    let font = UIFont(name: "Circe-Regular", size: 20)
    cell.textLabel?.font = font
    cell.backgroundColor = UIColor(red: 21/255, green: 45/255, blue: 71/255, alpha: 1)
    return cell
  }

  func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
    return 48
  }

  func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
    sublocationIndex = indexPath.row
    resignFirstResponder()
    sublocationPickerDelegate?.setupFloor(indexPath.row)
  }
}
