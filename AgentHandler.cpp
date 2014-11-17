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
    
    //TODO - Temporary. Replace with final verison.
    unique_ptr<Trait> sexTrait(new SexTrait);
    unique_ptr<Trait> ageTrait(new AgeTrait);
    unique_ptr<Trait> occupationTrait(new OccupationTrait);
    unique_ptr<Trait> meritalStatusTrait( new MeritalStatusTrait);
    
    long agentId = this->generateAgentId();
    unique_ptr<Agent> newAgent (new Agent(agentId));
    newAgent->traits.push_back(std::move(sexTrait));
    newAgent->traits.push_back(std::move(ageTrait));
    newAgent->traits.push_back(std::move(occupationTrait));
    newAgent->traits.push_back(std::move(meritalStatusTrait));
    
    this->agentStorage[agentId] = std::move(newAgent);
    return agentId;
}

void AgentHandler::setupAgent(long agentId) {
    
}

bool AgentHandler::removeAgent(long agentId) {
    cout << "AgentHandler: removeAgent " << endl;
    size_t agentsRemoved = this->agentStorage.erase(agentId);
    return agentsRemoved == 0 ? true : false;
}

std::vector<long> AgentHandler::findClosestAgents(long agentId, int closestCount) {
    cout << "Finding " << closestCount << " nearest neighbors of " << agentId << endl;
    
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

