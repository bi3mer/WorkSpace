//
//  main.swift
//  recursion
//
//  Created by colan biemer on 4/2/15.
//  Copyright (c) 2015 colan biemer. All rights reserved.
//

import Foundation

func factorial(num: Int) -> Int
{
    if(num ==  1)
    {
        return 1
    }
    return num * factorial(num-1)
}

println("factorial of 5: \(factorial(5))")

