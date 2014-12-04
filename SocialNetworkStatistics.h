//
//  SocialNetworkStatistics.h
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 03/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__SocialNetworkStatistics__
#define __Network_Dynamics__SocialNetworkStatistics__

#include <iostream>
#include <vector>
#include <boost/graph/clustering_coefficient.hpp>
#include <boost/graph/exterior_property.hpp>
#include "SocialNetworkHeaders.h"

typedef boost::exterior_vertex_property<Graph, float> ClusteringProperty;
typedef ClusteringProperty::container_type ClusteringContainer;
typedef ClusteringProperty::map_type ClusteringMap;

class SocialNetworkStatistics {
private:
    const Graph& graph;
    double degreeAverage;
    double clusteringCoefficient;
    
    void calculateAverageDegree();
    void calculateClusteringCoefficient();
    
public:
    SocialNetworkStatistics(const Graph& graphReference);
    void calculateStatistics();
    void printStatistics();
    

    
};

#endif /* defined(__Network_Dynamics__SocialNetworkStatistics__) */
