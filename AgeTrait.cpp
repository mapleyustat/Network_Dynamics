//
//  AgeTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "AgeTrait.h"

using namespace std;

AgeTrait::AgeTrait() {
    int randomIndex = rand() % Age::COUNT;
    this->value = Age(randomIndex);
}

int AgeTrait::getValue() const {
    return static_cast<std::underlying_type<Age>::type>(this->value);
}

string AgeTrait::toString() {
    return "toString: SexTrait";
}

//double AgeTrait::compareWithTrait(const Trait& trait) const {
//    return 0.0;
//}
