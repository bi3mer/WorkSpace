//
//  Shape.swift
//  Builder
//
//  Created by colan biemer on 4/4/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

class Shape
{
	var color: Color
	
	init(c : Color)
	{
		color = c
	}
	
	func printShape()
	{
		println("Shape invlaid, color \(color.applyColor())")
	}
}