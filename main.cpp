//
//  main.cpp
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#include <iostream>
#include "AgentHandler.h"
#include "SocialNetworkGraph.h"
#include <boost/graph/graphviz.hpp>

#include "Agent.h"
#include "Trait.h"


using namespace std;
using namespace boost;


int main() {
    srand (time(NULL));
    

    Agent& a();
    Agent& b();
    
    SocialNetworkGraph g;

    g.generateRandomSocialGraph(50000,10);
    
    //g.generateGraphiz("bla");
    
    cout<<"dupa";
    

    return 0;
}