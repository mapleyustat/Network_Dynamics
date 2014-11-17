//
//  main.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include <iostream>
#include "AgentHandler.h"
#include "SocialNetworkGraph.h"
#include <boost/graph/graphviz.hpp>

#include "Agent.h"
#include "Trait.h"
#include "SexTrait.h"


using namespace std;
using namespace boost;


int main() {
    srand (1);
    
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
    
    Agent& a();
    Agent& b();
    
    SocialNetworkGraph g;

    g.generateRandomSocialGraph(50000,10);
    
    //g.generateGraphiz("bla");
    
    cout<<"End";

    return 0;
}