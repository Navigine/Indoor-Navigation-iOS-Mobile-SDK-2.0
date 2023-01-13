//
//  NCError.swift
//  Navigine
//
//  Created by Dmitry Stavitsky on 15/11/2019.
//  Copyright © 2019 Navigine. All rights reserved.
//

import Foundation

enum NCError: Error {
  public enum NetworkFailure: Error {
    case responseDecodingFailed
    case parametersEncodingFailed
    case internalError
    case unknownError
    case networkError

    public enum LoginFailureReason: Error {
      case invalidCredentials
    }

    public enum AvatarFailureReason: Error {
      case invalidURL
      case invalidData
    }
  }

  public enum LocationDataManagerFailure: Error {
    case invalidData
  }

  public enum NavigationFailure: Error {
    public enum NavigationFailureReason: Error {
      case gpsUnavailable
      case bleUnavailable
      case errorCode4
      case errorCode30
      case anotherError

      var localizedDescription: String {
        switch self {
        case .gpsUnavailable:
          return "Your GPS is not enabled, please turn it on to get the Navigation results!"
        case .bleUnavailable:
          return "Your Bluetooth is not enabled, please turn it on to get the Navigation results!"
        case .errorCode4:
          return "You are out of navigation zone! Please, check that you added correct transmitters and transmitters are visible in this location!"
        case .errorCode30:
          return "Not enough beacons on the location! Please, switch to the `Add beacon` and add more transmitters!"
        
        default:
          return "Unknown error! Please contact technical support!"
        }
      }
    }

  }
}

extension NCError.NetworkFailure {
  var localizedDescription: String {
    switch self {
    case .responseDecodingFailed:
      return "Error while parsing response"
    case .internalError:
      return "Internal server error"
    case .parametersEncodingFailed:
      return "Error while encoding params"
    case .networkError:
      return "Internet connection lost"
    default:
      return "Unknown error"
    }
  }
}

extension NCError.NetworkFailure.LoginFailureReason {
  var localizedDescription: String {
    switch self {
      case .invalidCredentials:
        return "Invalid login or password"
    }
  }
}
