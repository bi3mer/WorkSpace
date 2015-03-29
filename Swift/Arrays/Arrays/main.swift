//
//  main.swift
//  Arrays
//
//  Created by colan biemer on 3/28/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

// Array
var list = [1,2,3,4,5]
list[1]=1000
println("value \(list[1])")

// Dictionary
var dict = [
    "x": 1,
    "y": 2,
]

// I have no idea why the ! is necessary right now
println("x: " + NSString(format: "%i", dict["x"]!))
println("y: " + NSString(format: "%i", dict["y"]!))

