//
//  SocialNetworkStatistics.cpp
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 03/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "SocialNetworkStatistics.h"

SocialNetworkStatistics::SocialNetworkStatistics(const Graph& graphReference) : graph(graphReference) {
    this->degreeAverage = 0;
    this->degreeMinimum = 0;
    this->degreeMaximum = 0;
    
}

void SocialNetworkStatistics::calculateDegree() {
    unsigned long degreeSum;
    graph_traits<Graph>::vertex_iterator vIter, vIter_End;
    for (tie(vIter, vIter_End) = vertices(this->graph); vIter != vIter_End; ++vIter) {
        unsigned long currentDegree = degree(*vIter, this->graph);
        
        this->degrees.push_back(currentDegree);
        if (currentDegree > this->degreeMaximum) {
            this->degreeMaximum = currentDegree;
        } else if (currentDegree < this->degreeMinimum) {
            this->degreeMinimum = currentDegree;
        }
        cout << "Vertex degree: " << degree(*vIter, this->graph);
    }
    this->degreeAverage = (double) degreeSum / degrees.size();
    cout << "Degree AVG: " << this->degreeAverage << " MIN: " << this->degreeMinimum << " MAX: " << this->degreeMaximum << endl;
}