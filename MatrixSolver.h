//
// Created by yanivmadmon on 1/21/20.
//

#ifndef MILESTONE2_MATRIXSOLVER_H
#define MILESTONE2_MATRIXSOLVER_H

#include "Searcheable.h"
#include "Searcher.h"
#include "Solver.h"


class MatrixSolver : public Solver<vector<string> , string>{
    Searcher<string> *searcher;
public:
    MatrixSolver(Searcher<string> *searcher){this->searcher = searcher;};
    string solve(vector<string> matrix);
};


#endif //MILESTONE2_MATRIXSOLVER_H
