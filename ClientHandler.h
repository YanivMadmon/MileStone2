//
// Created by shilo on 13.1.2020.
//

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H
//ds
#include <fstream>
#include <stdio.h>

class ClientHandler {
public:
virtual void handleClient(int sock_fd) = 0;
virtual std::string  getSolverName()=0 ;
};


#endif //MILESTONE2_CLIENTHANDLER_H
