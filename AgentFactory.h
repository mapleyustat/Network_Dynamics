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
#include "Agent.h"

class AgentFactory {
    
    AgentFactory()=delete;
    AgentFactory(const AgentFactory&)=delete;
    AgentFactory(AgentFactory&&)=delete;
    
public:
    static std::unique_ptr<Agent> createAgent();

};

#endif /* defined(__Network_Dynamics__AgentFactory__) */
