//
// Created by yanivmadmon on 1/14/20.
//

#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H

template <typename P, typename S>
class Solver {
public:
    virtual S solve(P problem)=0;
   // virtual ~Solver() = 0 ;
};
//ds

#endif //MILESTONE2_SOLVER_H
