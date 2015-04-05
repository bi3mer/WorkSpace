//
//  GlassBuilder.swift
//  Bridge
//
//  Created by colan biemer on 4/4/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

class GlassBuilder: Builder
{
	var obj: ComplexObject
	
	init()
	{
		obj = ComplexObject()
	}
	
	func buildNumber()
	{
		obj.setNum(200)
	}
	func buildValue()
	{
		obj.setVal(200)
	}
	func buildDefinition()
	{
		obj.setDef("This is glass")
	}
	func getObj() -> ComplexObject
	{
		return obj
	}
}