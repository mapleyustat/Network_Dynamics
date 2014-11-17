//
//  OccupationTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "OccupationTrait.h"

int OccupationTrait::getValue() {
    return 1;
}

double OccupationTrait::compareWithTrait(const Trait& trait) {
    return 0.0;
}

double OccupationTrait::operator&&(const Trait& traitA) {
    return 0.0;
}