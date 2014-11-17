//
//  MeritalStatusTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "MeritalStatusTrait.h"

int MeritalStatusTrait::getValue() {
    return 1;
}

double MeritalStatusTrait::compareWithTrait(const Trait& trait) {
    return 0.0;
}

double MeritalStatusTrait::operator&&(const Trait& traitA) {
    return 0.0;
}