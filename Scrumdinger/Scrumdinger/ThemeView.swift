//
//  ThemeView.swift
//  Scrumdinger
//
//  Created by Hojin Jang on 2023/03/22.
//

import SwiftUI

struct ThemeView: View {
    let theme: Theme

    var body: some View {
        ZStack {
            RoundedRectangle(cornerRadius: 4)
                .fill(theme.mainColor)
                .foregroundColor(theme.accentColor)
                .background(theme.mainColor)
                .cornerRadius(4)
            Label(theme.name, systemImage: "paintpalette")
                .padding(4)
        }
        .fixedSize(horizontal: false, vertical: true)
    }
}

struct ThemeView_Previews: PreviewProvider {
    static var previews: some View {
        ThemeView(theme: .indigo)
    }
}
