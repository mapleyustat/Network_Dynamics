//
//  OccupationTrait.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__OccupationTrait__
#define __Network_Dynamics__OccupationTrait__

#include <stdio.h>
#include "Trait.h"

class OccupationTrait: Trait {
public:
    enum class Occupation {
      Student, Employed, Unemployed
    };

    int getValue();
    double compareWithTrait(const Trait& trait);
    double operator&&(const Trait& traitA);
    
private:
    Occupation value;
};
#endif /* defined(__Network_Dynamics__OccupationTrait__) */
