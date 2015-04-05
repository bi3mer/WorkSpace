//
//  Rectangle.swift
//  Builder
//
//  Created by colan biemer on 4/4/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

class Rectangle : Shape
{
	override init(c: Color)
	{
		super.init(c: c)
	}
	
	override func printShape()
	{
		println("Rectangle of color \(color.applyColor())")
	}
}