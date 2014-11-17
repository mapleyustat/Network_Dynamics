//
//  OccupationTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "OccupationTrait.h"

using namespace std;

OccupationTrait::OccupationTrait() {
    int randomIndex = rand() % Occupation::COUNT;
    this->value = Occupation(randomIndex);
}

int OccupationTrait::getValue() const {
    return static_cast<std::underlying_type<Occupation>::type>(this->value);
}

string OccupationTrait::toString() {
    return "toString: OccupationTrait";
}