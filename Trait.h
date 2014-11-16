//
//  Trait.h
//  Network_Dynamics
//
//  Created by Wojtek on 14/11/14.
//  Copyright (c) 2014 Wojtek. All rights reserved.
//

#ifndef __Network_Dynamics__Trait__
#define __Network_Dynamics__Trait__

#include <iostream>

class Trait {
public:
    virtual int getValue() = 0;
    friend double compareTraits(const Trait& traitA, const Trait& traitB);
    friend double operator&&(const Trait& traitA, const Trait& traitB);
    virtual ~Trait() {
        
    }
};

class Age: public Trait {
public:
    int getValue() {
        return 2;
    }
    
    ~Age() {
        
    }
};

class Sex: public Trait {
public:
    int getValue() {
        return 1;
    }
    
    ~Sex() {
        
    }
};


#endif /* defined(__Network_Dynamics__Trait__) */
