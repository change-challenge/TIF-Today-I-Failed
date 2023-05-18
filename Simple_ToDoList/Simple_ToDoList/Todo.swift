//
//  Todo.swift
//  Simple_ToDoList
//
//  Created by Hojin Jang on 2023/05/11.
//

import Foundation

struct Todo {
    let title: String
    let isComplete: Bool
    
    init(title: String, isComplete: Bool = false) {
        self.title = title
        self.isComplete = isComplete
    }
    
    func completeToggled() -> Todo {
        return Todo(title: title, isComplete: !isComplete)
    }
}
