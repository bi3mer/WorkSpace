//
//  main.swift
//  for and if
//
//  Created by colan biemer on 3/28/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

let scores = [1,2,3,4,5,6,7]
var val = 0;

// Array
for score in scores
{
    if(score > 4)
    {
        val += score
    }
    else
    {
        val++
    }
}
println("if statement val: " + String(val))

// include 10
val = 0
for i in 0...10
{
    val++
}

println("include 10: " + String(val))

// familiar for loop
val = 0
for var i = 0; i < 4; i++
{
    val++
}
println("familiar for loop: " + String(val))

//disclude 10
val = 0
for i in 0..<10
{
    val++
}
println("disclude 10: " + String(val))

// dictionary
let dict =
[
    "w": 0,
    "x": 1,
    "y": 2,
    "z": 3,
]

for (key, val) in dict
{
    println(key + ": " + String(val))
}