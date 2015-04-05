//
//  ComplexObject.swift
//  Bridge
//
//  Created by colan biemer on 4/4/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

class ComplexObject
{
	var value: Int = 0
	var numberOfStuff: Int = 0
	var definition: String = ""
	
	func print()
	{
		println("val: \(value), num: \(numberOfStuff), def: \(definition)")
	}
	
	func setVal(val: Int)
	{
		value = val
	}
	
	func getVal() -> Int
	{
		return value
	}
	
	func setNum(num: Int)
	{
		numberOfStuff = num
	}
	
	func getNum() -> Int
	{
		return numberOfStuff
	}
	
	func setDef(def: String)
	{
		definition = def
	}
	
	func getDef() -> String
	{
		return definition
	}
}