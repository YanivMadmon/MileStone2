//
// Created by shilo on 20.1.2020.
//

#ifndef MILESTONE2_SEARCHEABLE_H
#define MILESTONE2_SEARCHEABLE_H

#include <stdio.h>
#include "State.h"
#include <vector>
using namespace std;

class Searcheable {
public:
    virtual State* getInitialState() =0;
    virtual State* getGoalState() =0 ;
    virtual vector<State*>* getAllPosibleStates(State* s) =0 ;
};


#endif //MILESTONE2_SEARCHEABLE_H
