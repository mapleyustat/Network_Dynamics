//
//  Trait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "Trait.h"

using namespace std;

double compareTraits(const Trait& traitA, const Trait& traitB) {
    cout << "Comparing Traits";
    return 0.0;
}

double operator&&(const Trait& traitA, const Trait& traitB) {
    return compareTraits(traitA, traitB);
}

