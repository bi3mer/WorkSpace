//
//  main.swift
//  printINt
//
//  Created by colan biemer on 3/28/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

var int: Int = 1
var double: Double = 2
let float: Float = 3

// Implicist conversion
let testInt =  "testing \(int) string"
let testDouble = "testing \(double) string"
let testFloat = "testing \(float) string"


println("int: "    + String(int));
println("Double: " + NSString(format:"%.2f",double))
println("Float: "  + NSString(format:"%.2f",float));
println(testInt)
println(testDouble)
println(testFloat)

