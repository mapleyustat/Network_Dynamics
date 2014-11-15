//
//  AgentFactory.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "AgentFactory.h"


using namespace std;

unique_ptr<Agent> AgentFactory::createAgent() {
    unique_ptr<Agent> pointer(new Agent);
    return pointer;
}