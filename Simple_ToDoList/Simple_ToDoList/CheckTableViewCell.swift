//
//  CheckTableViewCell.swift
//  Simple_ToDoList
//
//  Created by Hojin Jang on 2023/05/11.
//

import UIKit

protocol CheckTableViewCellDelegate: AnyObject {
    func checkTableViewCell(_ cell: CheckTableViewCell,
                            didChangeCheckedState checked: Bool)
}

class CheckTableViewCell: UITableViewCell {

    @IBOutlet weak var label: UILabel!
    
    @IBOutlet weak var checkbox: CheckBox!
    
    weak var delegate: CheckTableViewCellDelegate?
    
    @IBAction func checked(_ sender: CheckBox) {
        print("checked")
        updateChecked()
        delegate?.checkTableViewCell(self, didChangeCheckedState: checkbox.checked)
    }
    
    func set(title: String, checked: Bool) {
        label.text = title
        set(checked: checked)
    }
    
    func set(checked: Bool) {
        checkbox.checked = checked
        updateChecked()
    }
    
    func updateChecked() {
        let attributedString = NSMutableAttributedString(string: label.text!)
        
        
        if checkbox.checked {
            attributedString.addAttributes([NSAttributedString.Key.strikethroughStyle: NSUnderlineStyle.single.rawValue], range: NSMakeRange(0, attributedString.length-1))
        } else {
            attributedString.removeAttribute(NSAttributedString.Key.strikethroughStyle, range: NSMakeRange(0, attributedString.length-1))
        }
        label.attributedText = attributedString
    }
    
}
