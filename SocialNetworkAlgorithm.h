//
//  SocialNetworkAlgorithm.h
//  Social Network
//
//  Created by Aleksander Wójcik on 01.12.2014.
//  Copyright (c) 2014 Aleksander Wójcik. All rights reserved.
//

#ifndef __Social_Network__SocialNetworkAlgorithm__
#define __Social_Network__SocialNetworkAlgorithm__

#include <stdio.h>
#include <vector>
#include "SocialNetworkGraph.h"
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>

class SocialNetworkAlgorithm{
private:
    
    std::vector<std::pair<long,int>> getIdDistancePairs(int DFSlimit);
    std::vector<std::pair<long,int>> collectedPairs;
    
    SocialNetworkGraph socialNetorkGraph;
    
public:
    void makeRandomConnections(int randomConnectionCount);
    
    class NetworkVisitor:public boost::default_dfs_visitor {
    private:
        int curentDepthCount;
        int maxDepth;
    public:
        NetworkVisitor(int maxDepth);
        void discover_vertex(boost::graph_traits<Graph>::vertex_descriptor u, Graph g);
        void finish_vertex(boost::graph_traits<Graph>::vertex_descriptor u, Graph g);
        bool operator()();
    };
    

};

#endif /* defined(__Social_Network__SocialNetworkAlgorithm__) */
