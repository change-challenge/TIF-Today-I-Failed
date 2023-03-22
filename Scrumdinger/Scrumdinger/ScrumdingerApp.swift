//
//  ScrumdingerApp.swift
//  Scrumdinger
//
//  Created by Hojin Jang on 2023/03/22.
//

import SwiftUI

@main
struct ScrumdingerApp: App {
    @State private var srcums = DailyScrum.sampleData
    var body: some Scene {
        WindowGroup {
            NavigationView {
                ScrumsView(scrums: $srcums)
            }
        }
    }
}
