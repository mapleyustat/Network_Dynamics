//
//  MeritalStatusTrait.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "MeritalStatusTrait.h"

using namespace std;

MeritalStatusTrait::MeritalStatusTrait() {
    int randomIndex = rand() % MeritalStatus::COUNT;
    this->value = MeritalStatus(randomIndex);
}

int MeritalStatusTrait::getValue() const {
    return this->value;
}

string MeritalStatusTrait::toString() {
    return "toString: MeritalStatusTrait";
}