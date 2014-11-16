//
//  main.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include <iostream>
#include "AgentHandler.h"
#include "Agent.h"
#include "Trait.h"
#include "SexTrait.h"


using namespace std;

int main() {

    AgentHandler& agentHandler = AgentHandler::getInstance();
    auto agentA = agentHandler.createAgent();
    auto agentB = agentHandler.createAgent();
    agentHandler.compareAgents(agentA, agentB);
    
    SexTrait st1;
    SexTrait st2;
    
    Trait* tA = &st1;
    Trait* tB = &st2;
    
    tA->compareWithTrait(*tB);
    st1.compareWithTrait(st2);
    
    

    return 0;
}