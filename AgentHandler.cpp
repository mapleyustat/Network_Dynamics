//
//  AgentFactory.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include "AgentHandler.h"


using namespace std;

AgentHandler::AgentHandler() {}

AgentHandler::~AgentHandler() {
    this->agentStorage.clear();
}

AgentHandler& AgentHandler::getInstance() {
    static AgentHandler instance;
    return instance;
}

long AgentHandler::generateAgentId() {
    static long nextId = 0;
    return ++nextId;
}

long AgentHandler::createAgent() {
    long agentId = this->generateAgentId();
    this->agentStorage[agentId] = unique_ptr<Agent>(new Agent(agentId));
    return agentId;
}

bool AgentHandler::removeAgent(long agentId) {
    cout << "AgentHandler: removeAgent " << endl;
    size_t agentsRemoved = this->agentStorage.erase(agentId);
    return agentsRemoved == 0 ? true : false;
}

std::vector<long> findClosestAgents(long agentId, int closestCount) {
    cout << "Finding " << closestCount << " nearest neighbors of " << agentId << endl;
    return vector<long>();
}

double AgentHandler::compareAgents(long firstAgentId, long secondAgentId) {
    Agent& firstAgent = *(this->agentStorage[firstAgentId]);
    Agent& secondAgentIter = *(this->agentStorage[secondAgentId]);
    firstAgent && secondAgentIter;
    
    return 0.0;
}

