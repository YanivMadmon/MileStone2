//
// Created by yanivmadmon on 1/17/20.
//

#ifndef MILESTONE2_MAIN_H
#define MILESTONE2_MAIN_H
#include "server_side.h"
#include "MySerialServer.h"
#include "ClientHandler.h"

#include <iterator>
#include <random>

#include "MySerialServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "CacheManager.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "MatrixSolver.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "Astar.h"
#include "MyParallelServer.h"


using namespace std;

namespace boot {
    class Main {
    public:
        int main(int argc,char* args[]){
            MatrixSolver *solver = new MatrixSolver(new Astar());
            string nameSolver = "Astar";
            CacheManager<string,string> *cache = new FileCacheManager<string>();
            MyParallelServer *server  =  new MyParallelServer();
            ClientHandler *client = new MyClientHandler(cache , solver,nameSolver);
            if (argc == 1){ // deafult port
                server->open(5600,client);
            }
            else{ // put the args[1] new port
                server->open(atoi(args[1]),client);
            }
        }
    };
};





#endif //MILESTONE2_MAIN_H
