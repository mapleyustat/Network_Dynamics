//
//  SocialNetworkAlgorithm.cpp
//  Social Network
//
//  Created by Aleksander Wójcik on 01.12.2014.
//  Copyright (c) 2014 Aleksander Wójcik. All rights reserved.
//

#include "SocialNetworkAlgorithm.h"

std::vector<std::pair<long,double>> SocialNetworkAlgorithm::getIdDistancePairs(long startId,int DFSlimit){
    std::vector<std::pair<long, double>> retVector;
    std::map<long,bool> isVisited;
    isVisited[startId]=true;
    Graph::adjacency_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = adjacent_vertices( socialNetorkGraph.idToVdMap[startId], socialNetorkGraph.mGraph );
    for (; vertexIt != vertexEnd; ++vertexIt){
        limitedDFS(startId,socialNetorkGraph.mGraph[(*vertexIt)].vertex_id,DFSlimit,1,retVector,isVisited);
    }
    return retVector;
}

void SocialNetworkAlgorithm::limitedDFS(long startId,long currentId, int DFSlimit,int currentLevel,std::vector<std::pair<long, double>>& retVector,std::map<long,bool>& visitMap){
    bool wasVisited=GetWithDef(visitMap,currentId,false);
    if(wasVisited==true||currentLevel>DFSlimit){
        return;
    }
    visitMap[currentId]=true;
    
    retVector.push_back(pair<long,double>(currentId,AgentHandler::getInstance().compareAgents(startId,currentId)));
    
    Graph::adjacency_iterator vertexIt, vertexEnd;
    boost::tie(vertexIt, vertexEnd) = adjacent_vertices( socialNetorkGraph.idToVdMap[currentId], socialNetorkGraph.mGraph );
    for (; vertexIt != vertexEnd; ++vertexIt){
        limitedDFS(startId,socialNetorkGraph.mGraph[(*vertexIt)].vertex_id,DFSlimit,currentLevel+1,retVector,visitMap);
    }
    
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

bool SocialNetworkAlgorithm::NetworkVisitor::operator()(){
    if(curentDepthCount+1>maxDepth){
        return true;
    }
    else{
        return false;
    }
}

void SocialNetworkAlgorithm::makeRandomConnections(int randomConnectionCount){
    long firstID,secondId;
    
    for(int i=0;i<randomConnectionCount;i++){
        firstID = socialNetorkGraph.getRandomId();
        secondId = socialNetorkGraph.getRandomId();
        
        if(firstID!=secondId){
            socialNetorkGraph.addEdge(firstID, secondId);
        }
    }
}