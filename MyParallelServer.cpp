//
// Created by yanivmadmon on 1/23/20.
//
#include "MyParallelServer.h"
#include "MatrixSolver.h"
#include "BestFirstSearch.h"
#include "DFS.h"
#include "BFS.h"
#include "Astar.h"
#include "MyClientHandler.h"
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <netinet/in.h>
#include <thread>
using namespace std ;

int MyParallelServer:: open(int port, ClientHandler* c){

        thread newThread(MyParallelServer::openS, port, c);
         newThread.join();
}
void MyParallelServer:: close(){

}
int MyParallelServer:: openS(int port , ClientHandler* clientHandler) {

    timeval timeOut;
    timeOut.tv_sec = 120;
    timeOut.tv_usec = 0;
    bool stopRun = false;
    int client_socket;

    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket" << std::endl;
        return -1;
    }

    //bind socket to IP address
    sockaddr_in address; //in means IP4
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //give me any IP allocated for my machine
    address.sin_port = htons(port);

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr << "Could not bind the socket to an IP" << std::endl;
        return -2;
    }

    //making socket listen to the port
    if (listen(socketfd, 5) == -1) {
        std::cerr << "Error during listening command" << std::endl;
        return -3;
    } else {
        std::cout << "Server is now listening ..." << std::endl;
    }
    while (!stopRun) {
            setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (char *) &timeOut, sizeof(timeOut));
            client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
            if (client_socket == -1) {
                if (errno == EWOULDBLOCK) {
                    std::cerr << "TimeOut" << std::endl;
                    return -5;

                } else {
                    std::cerr << "Error accepting client" << std::endl;
                    return -4;
                }
            }
        MyClientHandler *clone = new MyClientHandler(clientHandler);
        thread newThread(MyParallelServer::clientThread, client_socket, clone);
        newThread.detach();
    }
}
int MyParallelServer:: clientThread(int client_socket,ClientHandler* clientHandler) {
    clientHandler->handleClient(client_socket);
    return 0;
}

