//
//  AgeTrait.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__AgeTrait__
#define __Network_Dynamics__AgeTrait__

#include <stdio.h>
#include "Trait.h"

class AgeTrait: Trait {
public:
    enum class Age {
        Child, Adolescent, YoungAdult, Adult, MiddleAged, 
    };

    int getValue();
    double compareWithTrait(const Trait& trait);
    double operator&&(const Trait& traitA);
    
private:
    Age value;
};

#endif /* defined(__Network_Dynamics__AgeTrait__) */
