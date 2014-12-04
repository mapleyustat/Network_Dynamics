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
    this->clusteringCoefficient = 0;
    this->smallWorldDistance = 0;
    
}
void SocialNetworkStatistics::calculateStatistics() {
    this->calculateAverageDegree();
    this->calculateClusteringCoefficient();
    this->calculateMeanGeodesicDistance();
}

void SocialNetworkStatistics::calculateAverageDegree() {
        this->degreeAverage = (double) num_edges(this->graph) / num_vertices(this->graph);
}

void SocialNetworkStatistics::calculateClusteringCoefficient() {
    AlgorithmContainer coefs(num_vertices(this->graph));
    AlgorithmMap clusterMap(coefs, this->graph);
    this->clusteringCoefficient = all_clustering_coefficients(this->graph, clusterMap);
}

void SocialNetworkStatistics::calculateMeanGeodesicDistance() {
    DistanceMatrix distances(num_vertices(this->graph));
    DistanceMatrixMap distanceMatrix(distances, this->graph);
    WeightMap weightMap(1);
    floyd_warshall_all_pairs_shortest_paths(this->graph, distanceMatrix, weight_map(weightMap));
    
    AlgorithmContainer geodesics(num_vertices(this->graph));
    AlgorithmMap geodesicMap(geodesics, this->graph);
    this->smallWorldDistance = all_mean_geodesics(this->graph, distanceMatrix, geodesicMap);
}

void SocialNetworkStatistics::printStatistics() {
    cout << "====== SOCIAL GRAPH STATS ======" << endl;
    cout << "Average Degree: " << this->degreeAverage << endl;
    cout << "Clustering Coefficient: " << this->clusteringCoefficient << endl;
    cout << "Small World Distance: " << this->smallWorldDistance << endl;
    cout << "================================" << endl;
}