//
//  MeritalStatusTrait.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__MeritalStatusTrait__
#define __Network_Dynamics__MeritalStatusTrait__

#include <stdio.h>
#include "Trait.h"

class MeritalStatusTrait: public Trait {
public:
    enum class MeritalStatus {
        Single, Married, Divorced, Widowed
    };
    
    int getValue();
    double compareWithTrait(const Trait& trait);
    double operator&&(const Trait& traitA);

private:
    MeritalStatus value;
    
};

#endif /* defined(__Network_Dynamics__MeritalStatusTrait__) */
