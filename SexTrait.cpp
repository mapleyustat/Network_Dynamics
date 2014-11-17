//
//  SexTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "SexTrait.h"

using namespace std;

SexTrait::SexTrait() {
    int randomIndex = rand() % Sex::COUNT;
    this->value = Sex(randomIndex);
}

int SexTrait::getValue() const {
    return static_cast<std::underlying_type<Sex>::type>(this->value);
}

string SexTrait::toString() {
    return "toString: SexTrait";
}