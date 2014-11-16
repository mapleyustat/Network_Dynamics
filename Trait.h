//
//  Trait.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__Trait__
#define __Network_Dynamics__Trait__

#include <iostream>

class Trait {
public:
    virtual int getValue() = 0;
    virtual double compareWithTrait(const Trait& traitA) = 0;
    virtual double operator&&(const Trait& traitA) = 0;
};

#endif /* defined(__Network_Dynamics__Trait__) */
