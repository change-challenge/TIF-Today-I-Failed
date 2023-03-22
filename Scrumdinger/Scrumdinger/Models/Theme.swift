//
//  Theme.swift
//  Scrumdinger
//
//  Created by Hojin Jang on 2023/03/22.
//

import SwiftUI
// View를 만들 지 않아도, 스유에서는 Color 속성을 이용할 수 있다.
// 스유에서는 Color를 View 계층에 넣을 수 있는 View 인스턴트처럼 대한다.

enum Theme: String, Codable {
    case bubblegum
    case buttercup
    case indigo
    case lavender
    case magenta
    case navy
    case orange
    case oxblood
    case periwinkle
    case poppy
    case purple
    case seafoam
    case sky
    case tan
    case teal
    case yellow
    
    var accentColor: Color {
        switch self {
        case .bubblegum, .buttercup, .lavender, .orange, .periwinkle, .poppy, .seafoam, .sky, .tan, .teal, .yellow: return .black
        case .indigo, .magenta, .navy, .oxblood, .purple: return .white
        }
    }
    
    var mainColor: Color {
        Color(rawValue)
    }
}
