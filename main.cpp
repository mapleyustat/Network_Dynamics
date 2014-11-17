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
    
//    AgentHandler& agentHandler = AgentHandler::getInstance();
//    auto agentA = agentHandler.createAgent();
//    auto agentB = agentHandler.createAgent();
//    auto agentC = agentHandler.createAgent();
//    auto agentD = agentHandler.createAgent();
//    auto agentE = agentHandler.createAgent();
//    
//    agentHandler.printAgent(agentA);
//    agentHandler.printAgent(agentB);
//    agentHandler.printAgent(agentC);
//    agentHandler.printAgent(agentD);
//    agentHandler.printAgent(agentE);
//    
//    auto closest = agentHandler.findClosestAgents(agentA, 3);
//    cout << "Found closest:" << endl;
//    for (auto const& item : closest) {
//        cout << item << " ";
//    }
//    cout << endl;
//    
//    cout << "Agent similarity: " << agentHandler.compareAgents(agentA, agentB) << endl;
//    
//    
    
    //////////////////////////////////////////////////////
    
    SocialNetworkGraph g;
    g.generateSmallWorldSocialGraph(20, 6, 2, 60);
    //ofstream myfile;
    //myfile.open ("/Users/O10/Documents/myfile.dot");
    g.generateGraphiz(std::cout);
    //g.generateGraphiz(myfile);
    //myfile.close();

    return 0;
}