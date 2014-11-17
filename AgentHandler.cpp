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
    unique_ptr<Agent> newAgent (new Agent(agentId));
    AgentHandler::setupAgent(*newAgent);
    
    this->agentStorage[agentId] = move(newAgent);
    return agentId;
}

void AgentHandler::setupAgent(Agent& agent) {
    agent.traits.push_back(unique_ptr<Trait>(new SexTrait));
    agent.traits.push_back(unique_ptr<Trait> (new AgeTrait));
    agent.traits.push_back(unique_ptr<Trait> (new OccupationTrait));
    agent.traits.push_back(unique_ptr<Trait> (new MeritalStatusTrait));
}

bool AgentHandler::removeAgent(long agentId) {
    size_t agentsRemoved = this->agentStorage.erase(agentId);
    return agentsRemoved == 0 ? true : false;
}

std::vector<long> AgentHandler::findClosestAgents(long agentId, int closestCount) {
    //TODO - Replace with final version.
    vector<long> sampleVector = vector<long>();
    for (auto const& agentPair : this->agentStorage) {
        if ((*agentPair.second).agentId == agentId) {
            continue;
        } else {
            sampleVector.push_back((*agentPair.second).agentId);
        }
    }
    
    return vector<long>(sampleVector.begin(), sampleVector.begin() + closestCount);
}

double AgentHandler::compareAgents(long firstAgentId, long secondAgentId) {
    return *(this->agentStorage[firstAgentId]) && *(this->agentStorage[secondAgentId]);
}

void AgentHandler::printAgent(long agentId) {
    cout << *(this->agentStorage[agentId]);
}

