//
//  SocialNetworkGraph.h
//  Social Network
//
//  Created by Aleksander Wójcik on 15.11.2014.
//  Copyright (c) 2014 Aleksander Wójcik. All rights reserved.
//

#ifndef Social_Network_SocialNetworkGraph_h
#define Social_Network_SocialNetworkGraph_h
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>
#include "Agent.h"
#include "AgentHandler.h"
#include <map>

using namespace boost;
using namespace std;

struct vertex_info {
    long vertex_id;
};

typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS,vertex_info> Graph;


class SocialNetworkGraph{
private:
    Graph mGraph;
    map<long,Graph::vertex_descriptor> idToVdMap;
    long getRandomId();
    
public:
    /**
     SocialNetworkGraph default constructor.
     */
    SocialNetworkGraph();
    
    /**
     Function adds edge beetween 2 agents.
     @param idAgent1 Id of first agent.
     @param idAgent1 Id of second agent.
     */
    void addEdge(long idAgent1, long idAgent2);
    
    /**
     Function removes edge beetween 2 agents (if exists).
     @param idAgent1 Id of first agent.
     @param idAgent1 Id of second agent.
     */
    void removeEdge(long idAgent1, long idAgent2);
    
    /**
     Function adds Agent to the social graph.
     @param id Id of new agent.
     */
    void addAgent(long);
    
    /**
     Function removes agent from the Graph (if exists).
     @param id Id of agent.
     */
    void removeAgent(long id);
    
    /**
     Function generates social graph using random (naive) algorithm.
     @param nodes Inital number of agents (nodes) in the graph.
     @param macConnections Number of initial connections beetween most similar agents(nodes).
     */
    void generateRandomSocialGraph(long,long);
    
    /**
     Function generates social graph using Watts-Strogaz algorithm.
     @param nodes Inital number of agents (nodes) in the graph.
     @param connections Number of initial connections beetween most similar nodes.
     @param maxRandomConnections Maximum number of random connections beetween nodes.
     @param randomConnectionProbability Number in % indicating if a node has random connections.
     */
    void generateSmallWorldSocialGraph(long,int,int,int);
    
    /**
     Function exports social graph to DOT file format.
     @param stream Stream which will be used to export DOT file.
     */
    void generateGraphiz(std::ostream& stream);
    
    
};

#endif
