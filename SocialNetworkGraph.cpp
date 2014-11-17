//
//  SocialNetworkGraph.cpp
//  Social Network
//
//  Created by Aleksander Wójcik on 15.11.2014.
//  Copyright (c) 2014 Aleksander Wójcik. All rights reserved.
//

#include <stdio.h>
#include "SocialNetworkGraph.h"
#include "AgentHandler.h"



void SocialNetworkGraph::addAgent(long id){
    Graph::vertex_descriptor v = boost::add_vertex(mGraph);
    mGraph[v].vertex_id=id;
    idToVdMap.insert(std::pair<long,Graph::vertex_descriptor>(id,v));
}

void SocialNetworkGraph::addEdge(long idAgent1,long idAgent2){
    Graph::vertex_descriptor v1=idToVdMap[idAgent1];
    Graph::vertex_descriptor v2=idToVdMap[idAgent2];

    boost::add_edge(v1,v2,mGraph);
}

void SocialNetworkGraph::removeEdge(long id1, long id2){
    Graph::vertex_descriptor v1=idToVdMap[id1];
    Graph::vertex_descriptor v2=idToVdMap[id2];
    
    std::pair<Graph::edge_descriptor, bool> edgePair = boost::edge(v1, v2, mGraph);
    
    mGraph.remove_edge(edgePair.first);
}

SocialNetworkGraph::SocialNetworkGraph(){
    
}

void SocialNetworkGraph::generateGraphiz(std::ostream& stream){
    //std::ofstream dotfile (filename);
    boost::dynamic_properties dp;
    dp.property("node_id", boost::get(&vertex_info::vertex_id, mGraph));
    write_graphviz_dp(stream,mGraph,dp);
}

void SocialNetworkGraph::removeAgent(long id){
    Graph::vertex_descriptor v=idToVdMap[id];
    boost::remove_vertex(v, mGraph);
    idToVdMap.erase(id);
}

void SocialNetworkGraph::generateRandomSocialGraph(long nodes,long maxConnections){
    AgentHandler& handler=AgentHandler::getInstance();
    long nextId;
    for(long i=0;i<nodes;i++){
        nextId=handler.createAgent();
        addAgent(nextId);
    }
    long thisConnections;
    long connectedId;
    for (std::map<long,Graph::vertex_descriptor>::iterator it=idToVdMap.begin(); it!=idToVdMap.end(); ++it){
        nextId=it->first;
        thisConnections=rand()%(maxConnections+1);
        for(long i=0;i<thisConnections;i++){
            connectedId=getRandomId();
            if(nextId!=connectedId){
                addEdge(nextId, connectedId);
            }
        }
        
    }
}

void SocialNetworkGraph::generateSmallWorldSocialGraph(long nodes, int connections,int maxRandomConnections,int randomConnectionProbability){
    AgentHandler& handler=AgentHandler::getInstance();
    long nextId;
    long randomVertexId;
    int thisVertexRandom;
    int currentVertexRandomCount;
    std::vector<long> closestIds;
    
    
    for(long i=0;i<nodes;i++){
        nextId=handler.createAgent();
        addAgent(nextId);
    }
    
    for (std::map<long,Graph::vertex_descriptor>::iterator it=idToVdMap.begin(); it!=idToVdMap.end(); ++it){
        nextId=it->first;
        closestIds=handler.findClosestAgents(nextId, connections);
        for(std::vector<long>::iterator vIt=closestIds.begin();vIt!=closestIds.end();vIt++){
            addEdge(nextId, *vIt);
        }
    }
    
    for (std::map<long,Graph::vertex_descriptor>::iterator it=idToVdMap.begin(); it!=idToVdMap.end(); ++it){
        nextId=it->first;
        thisVertexRandom=rand()%100;
        if(thisVertexRandom<randomConnectionProbability){
            currentVertexRandomCount=(rand()%maxRandomConnections)+1;
            for(int i=0;i<currentVertexRandomCount;i++){
                randomVertexId=getRandomId();
                if(randomVertexId!=nextId){
                    addEdge(nextId, randomVertexId);
                }
            }
        }
    }
    
}


long SocialNetworkGraph::getRandomId(){
    long mapSize=idToVdMap.size();
    std::map<long,Graph::vertex_descriptor>::iterator it=idToVdMap.begin();
    std::advance(it,rand()%mapSize);
    return it->second;
}