//
//  ScrumdingerApp.swift
//  Scrumdinger
//
//  Created by Hojin Jang on 2023/03/22.
//

import SwiftUI

@main
struct ScrumdingerApp: App {
    var body: some Scene {
        WindowGroup {
            ScrumsView(scrums: DailyScrum.sampleData)
        }
    }
}
