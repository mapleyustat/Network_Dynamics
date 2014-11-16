//
//  AgentFactory.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__AgentFactory__
#define __Network_Dynamics__AgentFactory__

#include <iostream>
#include <unordered_map>
#include "Agent.h"



class AgentHandler {
private:
    std::unordered_map<long, std::unique_ptr<Agent>> agentStorage;
    
    /**
     AgentHandler class default constructor.
     */
    AgentHandler();
    
    /**
     AgentHandler class copy constructor. (Deleted)
     */
    AgentHandler(const AgentHandler&)=delete;
    
    /** AgentHandler class rvalue copy constructor. (Deleted).
     */
    AgentHandler(AgentHandler&&)=delete;
    
    /**
     AgentHandler class default destructor.
     */
    ~AgentHandler();
    
    /**
     Function generates unique ID's for new agents.
     @return Unique ID generated for agent
     */
    long generateAgentId();
    
public:
    /**
     Get AgentHandler instance (Singleton class).
     */
    static AgentHandler& getInstance();
    
    /**
     Function creates new agent. Stored in AgentHandler.
     @return Unique agent identifier.
     */
    long createAgent();
    
    /**
     Function removes agent from AgentHandler.
     @param agentId ID of agent to be removed
     @return Boolean indicating if operation was successful
     */
    bool removeAgent(long agentId);
    
    /**
     Function compares two agents.
     @param firstAgentId ID of first agent to be compared
     @param secondAgentId ID of second agent to be compared
     @return Value indicating agent similarity
     */
    double compareAgents(long firstAgentId, long secondAgentId);

};

#endif /* defined(__Network_Dynamics__AgentFactory__) */