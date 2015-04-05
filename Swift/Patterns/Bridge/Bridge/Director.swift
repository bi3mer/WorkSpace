//
//  Director.swift
//  Bridge
//
//  Created by colan biemer on 4/4/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

class Director
{
	var builder: Builder
	init(bld: Builder)
	{
		builder = bld
	}
	
	func construct()
	{
		builder.buildDefinition()
		builder.buildNumber()
		builder.buildValue()
	}
	
	func getObj() -> ComplexObject
	{
		return builder.getObj()
	}
}