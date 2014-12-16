//
//  main.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include <iostream>
#include "SocialNetworkTest.h"

//#include <boost/graph/graphviz.hpp>
////#include "gvc.h"
//using namespace boost;


int main1 (){
    SocialNetworkTest testCase;
    testCase.runTest(SocialNetworkTest::InitGraph::SmallWorldGraph, 50, 8, 1, 10, 10, std::make_pair(0.05, 0.06), 0.01, std::make_pair(2, 3), 1, std::make_pair(1, 2), 1, "/Users/Wojtek/Desktop/Tests/");
    
//////    NIE WIEM CO TO
//////    std::ofstream myfile;
//////    myfile.open ("/Users/O10/Documents/myfile.dot");
//////    gr.generateGraphiz(myfile);
//////    myfile.close();
//////    
//////    
//////    GVC_t *gvc;
//////    Agraph_t *g;
//////    FILE *fp;
//////    
//////    gvc = gvContext();
//////    fp = fopen("/Users/O10/Documents/myfile.dot", "r");
//////    g = agread(fp,0);
//////    
//////   
//////    FILE *out=fopen("/Users/O10/Documents/out.png","w");
//////    
//////    gvLayout(gvc, g, "dot");
//////    gvRender(gvc, g, "png", out);
//////    gvFreeLayout(gvc, g);
//////    agclose(g);
//////    
//////    return (gvFreeContext(gvc));
    return 0;
}