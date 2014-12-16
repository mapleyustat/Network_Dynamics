////
////  main.cpp
////  Network_Dynamics
////
////  Created by Wojtek on 14/11/14.
////  Copyright (c) 2014 Wojtek. All rights reserved.
////
//
#include <iostream>
#include <boost/graph/graphviz.hpp>
#include "Trait.h"
#include "Agent.h"
#include "AgentHandler.h"
#include "SocialNetworkGraph.h"
#include "SocialNetworkAlgorithm.h"
//#include "gvc.h"
using namespace boost;

//#include "TestApp.h"

//int main() {
////    srand (1);
////    
//    SocialNetworkGraph gr;
//    SocialNetworkAlgorithm algorithms(gr);
//    std::ofstream myfile;
//    myfile.open ("/Users/O10/Documents/Network_Dynamicstest.txt");
//    myfile << "SIMULATION: " << time(NULL) <<std::endl;
//    myfile << "PARAMS: " << std::endl;
//    myfile << "=======START======" << std::endl;
//    algorithms.testSmallWorld(myfile, 500, 30, 2, 10, 100, 0.05, 5, 2);
//    
//
//
////  NIE WIEM CO TO
////    std::ofstream myfile;
////    myfile.open ("/Users/O10/Documents/myfile.dot");
////    gr.generateGraphiz(myfile);
////    myfile.close();
////    
////    
////    GVC_t *gvc;
////    Agraph_t *g;
////    FILE *fp;
////    
////    gvc = gvContext();
////    fp = fopen("/Users/O10/Documents/myfile.dot", "r");
////    g = agread(fp,0);
////    
////   
////    FILE *out=fopen("/Users/O10/Documents/out.png","w");
////    
////    gvLayout(gvc, g, "dot");
////    gvRender(gvc, g, "png", out);
////    gvFreeLayout(gvc, g);
////    agclose(g);
////    
////    return (gvFreeContext(gvc));
//    return 0;
//}
