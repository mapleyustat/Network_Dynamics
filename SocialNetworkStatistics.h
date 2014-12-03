//
//  SocialNetworkStatistics.h
//  Network_Dynamics
//
//  Created by Wojciech Kryscinski on 03/12/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__SocialNetworkStatistics__
#define __Network_Dynamics__SocialNetworkStatistics__

#include <stdio.h>
#include "SocialNetworkGraph.h"


class SocialNetworkStatistics {
private:
    const Graph& graph;
    std::vector<int> degrees;
    double degreeAverage;
    double degreeMaximum;
    double degreeMinimum;
    
public:
    SocialNetworkStatistics(const Graph& graphReference);
    void calculateDegree();
    
};

#endif /* defined(__Network_Dynamics__SocialNetworkStatistics__) */
