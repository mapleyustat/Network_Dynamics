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
    enum InitGraph {
        SmallWorldGraph = 1,
        RandomGraph = 2
    };
   
public:
    void runTest(InitGraph initGraphType, int nodeCnt, int initConCnt, int maxRndCon, int rndConProb, int iterCnt, std::pair<double, double> dfsProbRange, double dfsProbStep, std::pair<int, int> dfsLimitRange, int dfsLimitStep, std::pair<int, int> maxDfsConRange, int maxDfsConStep, std::string outputDir);
    
};

#endif /* defined(__Network_Dynamics__SocialNetworkTest__) */
