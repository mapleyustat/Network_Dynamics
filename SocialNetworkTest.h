//
//  SocialNetworkTest.h
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 16/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__SocialNetworkTest__
#define __Network_Dynamics__SocialNetworkTest__

#include <iostream>
#include "time.h"
#include "SocialNetworkAlgorithm.h"
#include "SocialNetworkStatistics.h"
#include "SocialNetworkGraph.h"

class SocialNetworkTest {
public:
    /*
     Enum specifies initial graph types
     */
    enum InitGraph {
        SmallWorldGraph = 1,
        RandomGraph = 2
    };
   
public:
    /*
     Function runs test with given parameters and ranges.
     @param initGraphType initial graph type
     @param nodeCnt number of nodes in graph
     @param initConCnt initial connection count
     @param maxRndCon maximal number of random connections in initial graph
     @param rndConProb random connection probability
     @param iterCnt number of epochs per test
     @param dfsProbRange range of dfs probabilities to be tested
     @param dfsProbStep step of dfs probabilities
     @param dfsLimitRange range of dfs limits to be tested
     @param dfsLimitStep step of dsf limits
     @param maxDfsConRange range of maximum number of dfs connections
     @param maxDfsConStep step of maximum number of dfs connections
     */
    void runTest(InitGraph initGraphType, int nodeCnt, int initConCnt, int maxRndCon, int rndConProb, int iterCnt, std::pair<double, double> dfsProbRange, double dfsProbStep, std::pair<int, int> dfsLimitRange, int dfsLimitStep, std::pair<int, int> maxDfsConRange, int maxDfsConStep, std::string outputDir);
    
};

#endif /* defined(__Network_Dynamics__SocialNetworkTest__) */
