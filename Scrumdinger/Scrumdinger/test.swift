//
//  test.swift
//  Scrumdinger
//
//  Created by Hojin Jang on 2023/04/17.
//

import SwiftUI

struct test: View {
    @State var name: String = "John" // @State 프로퍼티 래퍼 사용

        var body: some View {
            NavigationView {
                VStack {
                    Text("Hello, \(name)!")
                        .padding()

                    TextField("Enter your name", text: $name) // $ 기호를 사용하여 @Binding을 생성
                        .textFieldStyle(RoundedBorderTextFieldStyle())
                        .padding()

                    NavigationLink(destination: TestView(name: $name)) {
                        Text("Go to Detail View")
                    }
                }
                .navigationTitle("Home")
            }
        }
}

struct TestView: View {
    @Binding var name: String // @Binding 프로퍼티 래퍼 사용

    var body: some View {
        VStack {
            Text("Welcome, \(name)!")
                .padding()

            Button(action: {
                name = "Mike"
            }) {
                Text("Change name to Mike")
            }
        }
        .navigationTitle("Detail")
    }
}

struct test_Previews: PreviewProvider {
    static var previews: some View {
        test()
    }
}
