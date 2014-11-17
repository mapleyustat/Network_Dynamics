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
     Character of an agent. How easy is it to make new connections.
     */
    double character;
    
    /**
     Traits of an agent
     */
    std::vector<std::unique_ptr<Trait>> traits;
    
    /** 
     Values of an agent
     */
    std::vector<double> desirability;
    

public:
    /**
     Agent class default constructor
     */
    Agent(long agentId);
    
    /**
     Operator prints agent to stream.
     @param os output ostream
     @param agent agent to be printed
     @return output stream
     */
    friend std::ostream& operator<< (std::ostream& os, const Agent& agent);
    
    /**
     Function compares agent with an other agent. Trait based comparison.
     @param agentA other agent to be compared.
     @return real-valued similarity rate between agents.
     */
    double compareWithAgent(Agent& agentA);
    
    /**
     Overloaded operator for comparing agents. Uses compareWithAgent function.
     @param agentA other agent to be compared.
     @return real-valued similarity rate between agents.
     */
    double operator&&(Agent& agentA);
    
    friend class AgentHandler;
};

#endif /* defined(__Network_Dynamics__Agent__) */
