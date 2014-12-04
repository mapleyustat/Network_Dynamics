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
    //ofstream myfile;
    //myfile.open ("/Users/O10/Documents/myfile.dot");
    
    SocialNetworkGraph g;
    SocialNetworkAlgorithm algorithms(g);
    g.generateSmallWorldSocialGraph(100, 3, 3, 15);
    
    g.socialNetworkStatistics.calculateStatistics();
    g.socialNetworkStatistics.printStatistics();
    
    algorithms.makeMove(0.01, 2, 1);
    algorithms.makeMove(0.1, 2, 1);
    algorithms.makeMove(0.01, 2, 1);
    algorithms.makeMove(0.1, 2, 1);
    algorithms.makeMove(0.01, 2, 1);
    g.socialNetworkStatistics.calculateStatistics();
    g.socialNetworkStatistics.printStatistics();
    
//    g.generateGraphiz(std::cout);
    
    algorithms.makeMove(0.01, 2, 1);
    algorithms.makeMove(0.01, 2, 1);
    algorithms.makeMove(0.1, 2, 1);
    algorithms.makeMove(0.01, 2, 1);
    algorithms.makeMove(0.01, 2, 1);
    g.socialNetworkStatistics.calculateStatistics();
    g.socialNetworkStatistics.printStatistics();
    
    //SocialNetworkAlgorithm::NetworkVisitor mVisitor(4);
    //boost::depth_first_visit(g.mGraph,g.idToVdMap[g.getRandomId()] , boost::visitor(mVisitor),boost::default_color_type());
    //boost::depth_first_search(g.mGraph, boost::visitor(mVisitor))
    //std::vector<std::pair<long,double>> wektor=algorithms.getIdDistancePairs(1, 2);
    //for(std::vector<std::pair<long,double>>::iterator it=wektor.begin();it!=wektor.end();it++){
    //    cout<<"ID: "<<(*it).first<<" podobieństwo: "<<(*it).second<<endl;
    //}
    //g.generateGraphiz(myfile);
    //myfile.close();
    return 0;
}