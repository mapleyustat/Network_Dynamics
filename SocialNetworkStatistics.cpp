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
    this->calculateDegreeHistogram(this->graph);
    this->calculateClusteringCoefficient(this->graph);
    //this->calculateMeanGeodesicDistance();
}

void SocialNetworkStatistics::calculateDegreeHistogram(const Graph& analyzedGraph) {
    unsigned long currentDegree;
    this->degreeHistogram.clear();
    
    VertexIterator iterBegin, iterEnd;
    for (tie(iterBegin, iterEnd) = vertices(analyzedGraph); iterBegin != iterEnd; ++iterBegin) {
        currentDegree = degree(*iterBegin, analyzedGraph);
        ++(this->degreeHistogram[currentDegree]);
    }
        this->degreeAverage = (double) num_edges(analyzedGraph) / num_vertices(analyzedGraph);
}

void SocialNetworkStatistics::calculateClusteringCoefficient(const Graph& analyzedGraph) {
    AlgorithmContainer coefs(num_vertices(analyzedGraph));
    AlgorithmMap clusterMap(coefs, analyzedGraph);
    this->clusteringCoefficient = all_clustering_coefficients(analyzedGraph, clusterMap);
}

void SocialNetworkStatistics::calculateMeanGeodesicDistance(const Graph& analyzedGraph) {
    DistanceMatrix distances(num_vertices(analyzedGraph));
    DistanceMatrixMap distanceMatrix(distances, analyzedGraph);
    WeightMap weightMap(1);
    floyd_warshall_all_pairs_shortest_paths(analyzedGraph, distanceMatrix, weight_map(weightMap));
    
    AlgorithmContainer geodesics(num_vertices(analyzedGraph));
    AlgorithmMap geodesicMap(geodesics, analyzedGraph);
    this->smallWorldDistance = all_mean_geodesics(analyzedGraph, distanceMatrix, geodesicMap);
}

void SocialNetworkStatistics::printStatistics(std::ostream& output = std::cout) {
    output << "Average Degree: " << this->degreeAverage << endl;
    output << "Clustering Coefficient: " << this->clusteringCoefficient << endl;
    output << "Small World Distance: " << this->smallWorldDistance << endl;
    output << "Histogram: " << endl;
    output << "Degree: ";
    for (auto iter = this->degreeHistogram.begin(); iter != this->degreeHistogram.end(); ++iter) output << iter->first;
    output << endl << "Count: ";
    for (auto iter = this->degreeHistogram.begin(); iter != this->degreeHistogram.end(); ++iter) output << iter->second;

    output << endl << "================================" << endl;
}

const map<unsigned long, int>& SocialNetworkStatistics::getHistogram() {
    return this->degreeHistogram;
}