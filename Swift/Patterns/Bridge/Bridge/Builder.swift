//
//  Builder.swift
//  Bridge
//
//  Created by colan biemer on 4/4/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

protocol Builder
{
	func buildNumber()
	func buildValue()
	func buildDefinition()
	func getObj() -> ComplexObject
}