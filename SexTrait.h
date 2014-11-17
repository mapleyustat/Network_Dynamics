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
#include <vector>
#include "Trait.h"

class SexTrait: public Trait {
private:
    constexpr static const double statistics[] = { 0.515, 0.485 };
public:
    enum Sex {
        Male, Female, COUNT
    };
    
    SexTrait();
    int getValue() const;
    std::string toString();
    
private:
    Sex value;
};

#endif /* defined(__Network_Dynamics__SexTrait__) */
