//
//  main.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include <iostream>
#include "AgentFactory.h"
#include "Agent.h"
#include "Trait.h"


using namespace std;

int main() {

    auto agent = AgentFactory::createAgent();
    Agent& a();
    Agent& b();
    shared_ptr<Trait> traitA = make_shared<Sex>();
    shared_ptr<Trait> traitB = make_shared<Sex>();
    
    cout << *agent;
    return 0;
}