//
//  main.swift
//  functionHelloWorld
//
//  Created by colan biemer on 3/28/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

func hello() -> Void
{
    println("hello world!")
}

func hello(printVal: String)
{
    println("overload worked: " + printVal)
}

func returnHello() -> String
{
    return "hello world!"
}

func returnHello(str: String, str2: String) -> String
{
    return str + " " + str2
}

func minMax(arr: [Int]) -> (min: Int, max: Int)
{
    var min = arr[0]
    var max = arr[0]
    
    for val in arr
    {
        if( val > max )
        {
            max = val
        }
        else if(val < min)
        {
            min = val
        }
    }
    
    return (min,max)
}

hello()
hello("value")
println(returnHello())
println(returnHello("one", "two"))

var arr = [2,3,1235,6,123,123901,23,-123,123,-1234 ]
var mm  = minMax(arr)
println("min: \(mm.0) max: \(mm.1)")



