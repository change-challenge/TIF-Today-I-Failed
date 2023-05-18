//
//  CheckBox.swift
//  Simple_ToDoList
//
//  Created by Hojin Jang on 2023/05/11.
//

import UIKit

@IBDesignable
class CheckBox: UIControl {

    private weak var imageView: UIImageView!
    
    @IBInspectable
    public var checked: Bool = false {
        didSet {
            imageView.image = image
        }
    }
    
    private var image: UIImage {
        return checked ? UIImage(systemName: "checkmark.square.fill")! : UIImage(systemName: "square")!
    }
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        setup()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
        setup()
    }
    
    private func setup() {
        let imageView = UIImageView()
        imageView.translatesAutoresizingMaskIntoConstraints = false
        addSubview(imageView)
        
        imageView.leadingAnchor.constraint(equalTo: leadingAnchor).isActive = true
        imageView.bottomAnchor.constraint(equalTo: bottomAnchor).isActive = true
        imageView.trailingAnchor.constraint(equalTo: trailingAnchor).isActive = true
        imageView.trailingAnchor.constraint(equalTo: trailingAnchor).isActive = true
        
        imageView.image = image
        imageView.contentMode = .scaleAspectFill
        
        self.imageView = imageView
        
        backgroundColor = UIColor.clear
        addTarget(self, action: #selector(touchUpInside), for: .touchUpInside)
    }
    
    @objc func touchUpInside() {
        print("touchUpInside")
        checked = !checked
        sendActions(for: .valueChanged)
    }
}
