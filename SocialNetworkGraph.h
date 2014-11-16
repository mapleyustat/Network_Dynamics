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
    
public:
    SocialNetworkGraph();
    void addEdge(long, long);
    
    void removeEdge(long, long);
    
    void addAgent(long);
    
    void removeAgent(long);
    
    void generateRandomSocialGraph(long,long);
    void generateSmallWorldSocialGraph();
    
    void generateGraphiz(std::string filename);
    
    
};

#endif
