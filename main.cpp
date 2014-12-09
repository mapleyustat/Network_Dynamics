//
//  main.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include <iostream>
#include <boost/graph/graphviz.hpp>
#include "Trait.h"
#include "Agent.h"
#include "AgentHandler.h"
#include "SocialNetworkGraph.h"
#include "SocialNetworkAlgorithm.h"

using namespace boost;

#include "TestApp.h"

//int main() {
//    srand (1);
//    
//    SocialNetworkGraph g;
//    SocialNetworkAlgorithm algorithms(g);
//
//    g.generateSmallWorldSocialGraph(1500, 15, 3, 15);
//    
//    g.socialNetworkStatistics.calculateStatistics();
//    g.socialNetworkStatistics.printStatistics();
//    
//
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 4, 2);
//   g.socialNetworkStatistics.calculateStatistics();
//    g.socialNetworkStatistics.printStatistics();
//    
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 4, 2);
//    algorithms.makeMove(0.1, 2, 2);
//    algorithms.makeMove(0.1, 2, 2);
//    g.socialNetworkStatistics.calculateStatistics();
//    g.socialNetworkStatistics.printStatistics();
//    
//    //ofstream myfile;
//    //myfile.open ("/Users/O10/Documents/myfile.dot");
//    //g.generateGraphiz(myfile);
//    //myfile.close();
//    return 0;
//}