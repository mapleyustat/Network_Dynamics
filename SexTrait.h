//
//  SexTrait.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__SexTrait__
#define __Network_Dynamics__SexTrait__

#include <stdio.h>
#include "Trait.h"

class SexTrait: public Trait {
    enum class Sex {
        Male, Female
    };
    
public:
    int getValue();
    double compareWithTrait(const Trait& trait);
    double operator&&(const Trait& traitA);
};

#endif /* defined(__Network_Dynamics__SexTrait__) */
