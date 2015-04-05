//
//  main.swift
//  class
//
//  Created by colan biemer on 4/2/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//
//  basic inheritance

import Foundation

class Shape
{
    // Inital values
    var numSides = 0
    
    // Constructors
    init()
    {
    
    }
    
    init(num:Int)
    {
        numSides = num
    }
    
    // Description Funciton
    func Description() -> String
    {
        return "Number of sides: \(numSides)"
    }
}

class Sqaure: Shape
{
    var sideLength: Int
    
    init(numSideLength: Int)
    {
        sideLength = numSideLength
        super.init(num: 4)
    }
    
    override func Description() -> String
    {
        return "All squares have 4 sides and this one has a length of \(sideLength)"
    }
}

var shape = Shape()
shape.numSides = 20
println(shape.Description())

var square = Sqaure(numSideLength: 10)
println(square.Description())



