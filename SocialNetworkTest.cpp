//
//  SocialNetworkTest.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 16/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "SocialNetworkTest.h"


void SocialNetworkTest::runTest(InitGraph initGraphType, int nodeCnt, int initConCnt, int maxRndCon, int rndConProb, int iterCnt, std::pair<double, double> dfsProbRange, double dfsProbStep, std::pair<int, int> dfsLimitRange, int dfsLimitStep, std::pair<int, int> maxDfsConRange, int maxDfsConStep, std::string outputDir) {
    
    SocialNetworkGraph* snGraph;
    SocialNetworkAlgorithm* snAlgo;
    std::ofstream output;
    
    auto printHeader = [&](double dfsProb, int dfsLimit, int dfsCon) {
        output << "SIMULATION: " << time(NULL) << std::endl;
        output << "PARAMS: " << std::endl;
        output << "Graph Type: " << initGraphType << std::endl;
        output << "Node Count: " << nodeCnt << std::endl;
        output << "Initial Connection Count: " << initConCnt << std::endl;
        output << "Max Random Connections: " << maxRndCon << std::endl;
        output << "Random Connection Probability: " << rndConProb << std::endl;
        output << "Max Iterations: " << nodeCnt << std::endl;
        output << "DFS Probability: " << dfsProb << std::endl;
        output << "DFS Limit: " << dfsLimit << std::endl;
        output << "Max DFS Connections: " << dfsCon << std::endl;
    };
    
    auto generateGraph = [&]() {
        if (initGraphType == 1) {
            snGraph->generateSmallWorldSocialGraph(nodeCnt, initConCnt, maxRndCon, rndConProb);
        } else {
            snGraph->generateRandomSocialGraph(nodeCnt, initConCnt);
        }
    };
    
    auto openStream = [&] (double dfsProb, int dfsLimit, int dfsCon) {
        std::stringstream fileName;
        fileName << outputDir << initGraphType << "-" << dfsProb << "-" << dfsLimit << "-" << dfsCon << ".txt";
        output.open(fileName.str());
    };
    
    
    
    for (auto curDfsProb = dfsProbRange.first; curDfsProb <= dfsProbRange.second; curDfsProb += dfsProbStep) {
        for (auto curDfsLimit = dfsLimitRange.first; curDfsLimit <= dfsLimitRange.second; curDfsLimit += dfsLimitStep) {
            for (auto curMaxDfsCon = maxDfsConRange.first; curMaxDfsCon <= maxDfsConRange.second; curMaxDfsCon += maxDfsConStep) {
                snGraph = new SocialNetworkGraph;
                snAlgo = new SocialNetworkAlgorithm(*snGraph);
                openStream(curDfsProb, curDfsLimit, curMaxDfsCon);
                printHeader(curDfsProb, curDfsLimit, curMaxDfsCon);
                generateGraph();
                snAlgo->runTestVersion(output, iterCnt, curDfsProb, curDfsLimit, curMaxDfsCon);
                
                output.close();
                delete snGraph;
                delete snAlgo;
            }
        }
    }
}