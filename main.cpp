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


int main1(){
    SocialNetworkTest testCase;
    testCase.runTest(SocialNetworkTest::InitGraph::SmallWorldGraph, 500, 15, 1, 10, 500, std::make_pair(0.02, 0.08), 0.01, std::make_pair(2, 4), 1, std::make_pair(1, 2), 1, "/Users/O10/Documents/Tests/");
//    testCase.runTest(SocialNetworkTest::InitGraph::RandomGraph, 500, 15, 1, 10, 500, std::make_pair(0.02, 0.08), 0.01, std::make_pair(2, 4), 1, std::make_pair(1, 2), 1, "/Users/O10/Documents/Tests/");
    return 0;
}