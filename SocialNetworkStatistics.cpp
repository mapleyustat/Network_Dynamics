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
    graph_traits<Graph>::vertex_iterator vIter, vIter_End;
    for (tie(vIter, vIter_End) = vertices(this->graph); vIter != vIter_End; ++vIter) {
        cout << "I'm inside";
    }
}