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

class AgeTrait: public Trait {
private:
    constexpr static const double distribution[] = { 0.217, 0.316, 0.262, 0.167, 0.038 };
public:
    enum Age {
        Adolescent, YoungAdult, Adult, Old, VeryOld, COUNT
    };

    AgeTrait();
    int getValue() const;
    std::string toString();
    //double compareWithTrait(const Trait& trait) const;
private:
    Age value;
};

#endif /* defined(__Network_Dynamics__AgeTrait__) */
