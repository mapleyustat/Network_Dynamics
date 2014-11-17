//
//  AgeTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "AgeTrait.h"
int AgeTrait::getValue() {
    return 1;
}

double AgeTrait::compareWithTrait(const Trait& trait) {
    return 0.0;
}

double AgeTrait::operator&&(const Trait& traitA) {
    return 0.0;
}