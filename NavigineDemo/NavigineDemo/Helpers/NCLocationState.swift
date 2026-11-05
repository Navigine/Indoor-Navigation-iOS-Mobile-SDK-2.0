//
//  NCLocationState.swift
//  NavigineDemo-Beta
//
//  Created by Elvira Khabibullina on 06.06.2022.
//  Copyright © 2022 Navigine. All rights reserved.
//

import Foundation
import Navigine

enum NCLocationState: Int {
  case none
  case downloading
  case loaded
}

extension NCSublocation {
  func globalPoint(from localPoint: NCPoint, locationId: Int32) -> NCGlobalPoint {
    local(toGlobal: NCLocationPoint(point: localPoint, locationId: locationId, sublocationId: id))
  }
}

extension NCIconMapObject {
  func setLocationPosition(_ point: NCLocationPoint, in location: NCLocation?, window: NCLocationWindow) {
    guard let sublocation = location?.sublocations.first(where: { $0.id == point.sublocationId }) else { return }
    let sublocationId = window.getOperatingMode() == .indoorOnly ? NSNumber(value: sublocation.id) : nil
    setPosition(sublocation.local(toGlobal: point), sublocationId: sublocationId)
  }
}

func globalRouteSegments(for path: NCRoutePath, in location: NCLocation) -> [(sublocationId: Int32, points: [NCGlobalPoint])] {
  var segments: [(sublocationId: Int32, points: [NCGlobalPoint])] = []
  for node in path.nodes().reversed() {
    guard let sublocation = location.sublocations.first(where: { $0.id == node.point.sublocationId }) else { continue }
    let globalPoint = sublocation.local(toGlobal: node.point)
    if segments.last?.sublocationId == sublocation.id {
      segments[segments.count - 1].points.append(globalPoint)
    } else {
      segments.append((sublocation.id, [globalPoint]))
    }
  }
  return segments
}
