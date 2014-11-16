//
//  Agent.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__Agent__
#define __Network_Dynamics__Agent__

#define TRAIT_COUNT 5

#include <iostream>
#include <vector>
#include "Trait.h"

class Agent {
private:
    /**
     Value identifing an agent
     */
    long agentId;
    
    /**
     Traits of an agent
     */
    std::vector<Trait> traits;
    
public:
    /**
     Agent class default constructor
     */
    Agent(long agentId);
    
    /**
     Operator prints agent to stream.
     */
    friend std::ostream& operator<< (std::ostream& os, const Agent& agent);
    friend double compareAgents(Agent& agentA, Agent& agentB);
};


std::ostream& operator<< (std::ostream& os, const Agent& agent);
double compareAgents(Agent& agentA, Agent& agentB);

#endif /* defined(__Network_Dynamics__Agent__) */
