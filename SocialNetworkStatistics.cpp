//
//  SocialNetworkStatistics.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 03/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "SocialNetworkStatistics.h"

using namespace boost;
using namespace std;

SocialNetworkStatistics::SocialNetworkStatistics(const Graph& graphReference) : graph(graphReference) {
    this->degreeAverage = 0;
    
}
void SocialNetworkStatistics::calculateStatistics() {
    this->calculateAverageDegree();
    this->calculateClusteringCoefficient();
}

void SocialNetworkStatistics::calculateAverageDegree() {
        this->degreeAverage = (double) num_edges(this->graph) / num_vertices(this->graph);
}

void SocialNetworkStatistics::calculateClusteringCoefficient() {
    ClusteringContainer coefs(num_vertices(this->graph));
    ClusteringMap clusterMap(coefs, this->graph);
    this->clusteringCoefficient = all_clustering_coefficients(this->graph, clusterMap);
}

void SocialNetworkStatistics::printStatistics() {
    cout << "====== SOCIAL GRAPH STATS ======" << endl;
    cout << "Average degree: " << this->degreeAverage << endl;
    cout << "Clustering Coefficient: " << this->clusteringCoefficient << endl;
}