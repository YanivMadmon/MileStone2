//
// Created by yanivmadmon on 1/21/20.
//

#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H


#include "Searcheable.h"
#include "State.h"


class Matrix : public Searcheable{
    vector<vector<State*>>* MatrixStates;
    int n ;
    State* enter ;
    State* exit ;
public:
    Matrix(vector<string>* matrixString);
    State* getInitialState() override ;
    State* getGoalState() override  ;
    vector<State*>* getAllPosibleStates(State* s) override  ;
};


#endif //MILESTONE2_MATRIX_H
