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
#include "SocialNetworkAlgorithm.h"
#include "SocialNetworkAlgorithm.h"


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
    
    g.generateSmallWorldSocialGraph(20, 2, 2, 15);
    
    SocialNetworkAlgorithm::NetworkVisitor mVisitor(4);
    //boost::depth_first_visit(g.mGraph,g.idToVdMap[g.getRandomId()] , boost::visitor(mVisitor),boost::default_color_type());
    
    cout<<"danke";
    
    
    //boost::depth_first_search(g.mGraph, boost::visitor(mVisitor));
    
    cout<<"deupa" << endl;
    //g.getStatistics().calculateDegree();
    g.socialNetworkStatistics.calculateStatistics();
    g.socialNetworkStatistics.printStatistics();
    
    //ofstream myfile;
    //myfile.open ("/Users/O10/Documents/myfile.dot");
    g.generateGraphiz(std::cout);
    
    SocialNetworkAlgorithm algorithms(g);
    
//    std::vector<std::pair<long,double>> wektor=algorithms.getIdDistancePairs(1, 2);
//    
//    for(std::vector<std::pair<long,double>>::iterator it=wektor.begin();it!=wektor.end();it++){
//        cout<<"ID: "<<(*it).first<<" podobieństwo: "<<(*it).second<<endl;
//    }
    algorithms.makeMove(0.1, 2, 1);
    
    
    //g.generateGraphiz(myfile);
    //myfile.close();
    return 0;
}