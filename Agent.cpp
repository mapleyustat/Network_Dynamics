//
//  Agent.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "Agent.h"

using namespace std;

double compareAgents(Agent& agentA, Agent& agentB) {
    cout << "Comparing agents";
    return 0.0;
}

ostream& operator<< (ostream& os, const Agent& agent) {
    return os << "Writing out Agent data.\n";
}
