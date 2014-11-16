//
//  SocialNetworkGraph.cpp
//  Social Network
//
//  Created by Aleksander Wójcik on 15.11.2014.
//  Copyright (c) 2014 Aleksander Wójcik. All rights reserved.
//

#include <stdio.h>
#include "SocialNetworkGraph.h"


void SocialNetworkGraph::addAgent(Agent& agent){
    Graph::vertex_descriptor v = boost::add_vertex(mGraph);
    idToVdMap.insert(std::pair<int,Graph::vertex_descriptor>(agent.getId(),v));
}

void SocialNetworkGraph::addEdge(int idAgent1,int idAgent2){
    Graph::vertex_descriptor v1=idToVdMap[idAgent1];
    Graph::vertex_descriptor v2=idToVdMap[idAgent2];

    boost::add_edge(v1,v2,mGraph);
}

void SocialNetworkGraph::addEdge(const Agent & agent1,const Agent&  agent2){
    addEdge(agent1.getId(), agent2.getId());
}


void SocialNetworkGraph::removeEdge(int id1, int id2){
    Graph::vertex_descriptor v1=idToVdMap[id1];
    Graph::vertex_descriptor v2=idToVdMap[id2];
    
    std::pair<Graph::edge_descriptor, bool> edgePair = boost::edge(v1, v2, mGraph);
    
    mGraph.remove_edge(edgePair.first);
}

void SocialNetworkGraph::removeEdge(const Agent& agent1, const Agent& agent2){
    removeEdge(agent1.getId(), agent2.getId());
}

