//
//  SexTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "SexTrait.h"

using namespace std;

int SexTrait::getValue() {
    return 1;
}

double SexTrait::compareWithTrait(const Trait& trait) {
    cout << "Comparing SexTraits" << endl;
    return 0.0;
}

double SexTrait::operator&&(const Trait& traitA) {
    this->compareWithTrait(traitA);
    return 0;
}