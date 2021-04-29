//
// Created by yanivmadmon on 1/20/20.
//

#ifndef MILESTONE2_MYCLIENTHANDLER_H
#define MILESTONE2_MYCLIENTHANDLER_H
#include <stdio.h>
#include <string>
#include <vector>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

using namespace std ;

class MyClientHandler : public ClientHandler{
    Solver<vector<string>,string>* solver ;
    CacheManager<string,string>* cacheManager;
    string SolverName;
public:
    MyClientHandler(CacheManager<string,string>* cacheManager ,Solver<vector<string>, string>* Solver, string solvername ){this->cacheManager = cacheManager; this->solver = Solver;this->SolverName =solvername;};
    MyClientHandler(ClientHandler* clientHandler);
    void handleClient(int sock_fd);
    string  getSolverName(){return this->SolverName;};

};


#endif //MILESTONE2_MYCLIENTHANDLER_H
