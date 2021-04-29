//
// Created by yanivmadmon on 1/23/20.
//

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "server_side.h"


class MyParallelServer : public server_side::Server{

public:
    static int clientThread(int client_socket ,ClientHandler* clientHandler );
    int open(int port, ClientHandler* c);
    void  close();
    static int openS(int port , ClientHandler* clientHandler);
};


#endif //MILESTONE2_MYPARALLELSERVER_H
