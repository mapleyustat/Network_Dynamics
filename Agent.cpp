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
    this->traits = vector<unique_ptr<Trait>>();
}

double Agent::compareWithAgent(Agent& otherAgent) {
    //cout << "compare: Comparing agents" << endl;
    double similarityRate = 0.0;
    
    for (int i = 0; i < this->traits.size(); i++) {
        similarityRate += (*this->traits[i]) && (*otherAgent.traits[i]);
    }
    double returnValue = similarityRate / this->traits.size();
    return returnValue;
}

double Agent::operator&& (Agent& agentA) {
    //cout << "operator&&: Comparing agents" << endl;
    return this->compareWithAgent(agentA);
}

ostream& operator<< (ostream& os, const Agent& agent) {
    os << "AgentID: " << agent.agentId << endl;
    for (auto const& trait : agent.traits) {
        os << *trait << endl;
    }
    return os << endl;
}
