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
#include "Agent.h"
#include "AgentHandler.h"
#include <map>
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;

using namespace boost;
using namespace std;

class SocialNetworkGraph{
private:
    Graph mGraph;
    map<int,Graph::vertex_descriptor> idToVdMap;
    
public:
    SocialNetworkGraph();
    void addEdge(int, int);
    
    void removeEdge(int, int);
    
    void addAgent(int);
    
    void removeAgent(int);
    
    void generateRandomSocialGraph(AgentHandler&,int);
    void generateSmallWorldSocialGraph(AgentHandler&,int);
    
    
};

#endif
