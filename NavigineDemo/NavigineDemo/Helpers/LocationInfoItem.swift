//
//  LocationInfoItem.swift
//  Navigine
//
//  Created by Dmitry Stavitsky on 27/11/2019.
//  Copyright © 2019 Navigine. All rights reserved.
//

import UIKit

enum LocationInfoItemStatus: Equatable {
  // The initial state of the location when the user did not initiate the download
  case initial

  // Location in downloading state(only after download button pressed)
  case downloading

  // Location success downloaded
  case selected

  // Failure while downloading location or corrupted archive
  // TODO: Replace Int with NCError
  case failure(Int)

  // Location success downloaded and selected at now
  case unselected
  
  static func == (lhs: LocationInfoItemStatus, rhs: LocationInfoItemStatus) -> Bool {
    lhs.value == rhs.value
  }
  
  var value: String? {
    return String(describing: self).components(separatedBy: "(").first
  }
}

extension LocationInfoItemStatus: Codable {
  enum Key: CodingKey {
    case rawValue
    case associatedValue
  }

  enum CodingError: Error {
    case unknownValue
  }

  init(from decoder: Decoder) throws {
    let container = try decoder.container(keyedBy: Key.self)
    let rawValue = try container.decode(Int.self, forKey: .rawValue)
    switch rawValue {
    case 0:
      self = .initial
    case 1:
      let downloading = try container.decode(CGFloat.self, forKey: .associatedValue)
      self = .downloading
    case 2:
      self = .selected
    case 3:
      let code = try container.decode(Int.self, forKey: .associatedValue)
      self = .failure(code)
    case 4:
      self = .unselected
    default:
      throw CodingError.unknownValue
    }
  }

  func encode(to encoder: Encoder) throws {
    var container = encoder.container(keyedBy: Key.self)
    switch self {
    case .initial:
      try container.encode(0, forKey: .rawValue)

    case .downloading:
      try container.encode(1, forKey: .rawValue)
      try container.encode(value, forKey: .associatedValue)

    case .selected:
      try container.encode(2, forKey: .rawValue)

    case .failure(let error):
      try container.encode(3, forKey: .rawValue)
      try container.encode(error, forKey: .associatedValue)

    case .unselected:
      try container.encode(4, forKey: .rawValue)
    }
  }
}

protocol LocationInfoItemDelegate : class {
  func statusWillChanged(item: LocationInfoItem, newStatus: LocationInfoItemStatus)
}

class LocationInfoItem: Codable {
  weak var delegate: LocationInfoItemDelegate?

  enum CodingKeys: String, CodingKey {
    case info = "info"
    case status = "status"
    case selected = "selected"
    case title = "title"
    case version = "version"
    case descript = "descript"
    case identifier = "identifier"
  }

  required init(from decoder: Decoder) throws {
    let values = try decoder.container(keyedBy: CodingKeys.self)
    isSelected = try values.decode(Bool.self, forKey: .selected)
    status = try values.decode(LocationInfoItemStatus.self, forKey: .status)

    // Decoding info
    let title = try values.decode(String.self, forKey: .title)
    let version = try values.decode(Int32.self, forKey: .version)
    let identifier = try values.decode(Int32.self, forKey: .identifier)

    info = NCLocationInfo.init(id: identifier, version: version, name: title)
//    NavigineApp.mLocationManager?.add(self)
  }

//  deinit {
//    NavigineApp.mLocationManager?.remove(self)
//  }

  func encode(to encoder: Encoder) throws {
    var container = encoder.container(keyedBy: CodingKeys.self)
    try container.encode(status, forKey: .status)
    try container.encode(isSelected, forKey: .selected)

    // Encoding info
    try container.encode(info.name, forKey: .title)
    try container.encode(info.version, forKey: .version)
    try container.encode(info.id, forKey: .identifier)
  }

  var info: NCLocationInfo

  var status: LocationInfoItemStatus? {
    willSet(newStatus) {
      if newStatus == .selected {
        isSelected = true
      } else {
        isSelected = false
      }
      if let statusDidChanged = delegate?.statusWillChanged {
        statusDidChanged(self, newStatus!)
      }
    }
  }

  var isSelected: Bool

  init() {
    self.info = NCLocationInfo()
    self.isSelected = false
    status = .initial
  }
}

extension LocationInfoItem: Equatable {
  static func == (lhs: LocationInfoItem, rhs: LocationInfoItem) -> Bool {
    return lhs.info.id == rhs.info.id
  }

  static func == (lhs: LocationInfoItem, rhs: NCLocationInfo) -> Bool {
    return lhs.info.id == rhs.id
  }

  static func == (lhs: NCLocationInfo, rhs: LocationInfoItem) -> Bool {
    return rhs == lhs
  }
}
