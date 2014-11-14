//
//  Agent.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "Agent.h"
#include <iostream>

int main() {
    std::cout << "Hello, Wordl!\n";
    auto helloFunc = [] () {
        std::cout << "I'm a lambda function\n";
    };
    helloFunc();
    return 0;
}