//
//  SocialNetworkAlgorithm.cpp
//  Social Network
//
//  Created by Aleksander Wójcik on 01.12.2014.
//  Copyright (c) 2014 Aleksander Wójcik. All rights reserved.
//

#include "SocialNetworkAlgorithm.h"

std::vector<std::pair<long, int>> SocialNetworkAlgorithm::getIdDistancePairs(int DFSlimit){
    std::vector<std::pair<long, int>> retVector;
    return retVector;
}

SocialNetworkAlgorithm::NetworkVisitor::NetworkVisitor(int maxDepth){
    this->maxDepth=maxDepth;
    curentDepthCount=0;
}

void SocialNetworkAlgorithm::NetworkVisitor::discover_vertex(boost::graph_traits<Graph>::vertex_descriptor u, Graph g){
    cout<<"discover vertex called current Depth "<<curentDepthCount<<endl;
    curentDepthCount++;
}

void SocialNetworkAlgorithm::NetworkVisitor::finish_vertex(boost::graph_traits<Graph>::vertex_descriptor u, Graph g){
    cout<<"finish vertex called current Depth "<<curentDepthCount<<endl;
    curentDepthCount--;
}

bool::SocialNetworkAlgorithm::NetworkVisitor::operator()(){
    if(curentDepthCount+1>maxDepth){
        return true;
    }
    else{
        return false;
    }
}