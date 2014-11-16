//
//  Agent.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "Agent.h"

using namespace std;

Agent::Agent(long agentId) {
    this->agentId = agentId;
    //this->traits = vector<Trait>();
}

double compare(Agent& agentA, Agent& agentB) {
    cout << "compare: Comparing agents" << endl;
    return 0.0;
}

double operator&& (Agent& agentA, Agent& agentB) {
    cout << "operator&&: Comparing agents" << endl;
    return 0.0;
}

ostream& operator<< (ostream& os, const Agent& agent) {
    return os << "Writing out Agent data.\n";
}
