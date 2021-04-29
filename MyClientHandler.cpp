//
// Created by yanivmadmon on 1/20/20.
//

#include "MyClientHandler.h"
#include "MatrixSolver.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "Astar.h"
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void MyClientHandler:: handleClient(int client_socket)
{
  //  string arr[40] ;
    string line="";
    string hashMat = "";
    vector<string> matrix;
    while(true) {
        char buffer[4096] = {0};
        int valread = read(client_socket, buffer, 4096);
        if (valread < 0) {
            perror("ERROR reading from socket");
            break;
        }
        line = "";
        for (char c:buffer) {
            if (c == '\n') {
                if (line == "end") {
                    break;
                }
                hashMat= hashMat+line;
                matrix.push_back(line);
                break;
            }
            line += c;
        }
        if (line == "end") {
            if (cacheManager->ifExistSolution(hashMat)) {
                mtx.lock();
                string strSol = cacheManager->get(hashMat);
                int n = strSol.length();
                char char_array[n + 1];
                strcpy(char_array, strSol.c_str());
                send(client_socket, char_array, strlen(char_array), 0);
                mtx.unlock();
            } else {
               mtx.lock();
                string strSol = solver->solve(matrix);
                cacheManager->insert(hashMat, strSol);
                int n = strSol.length();
                char char_array[n + 1];
                strcpy(char_array, strSol.c_str());
                send(client_socket, char_array, strlen(char_array), 0);
                mtx.unlock();
            }
            return ;
        }
    }
}
MyClientHandler:: MyClientHandler(ClientHandler* clientHandler){
    string nameSolver = clientHandler->getSolverName();
    if ( nameSolver.compare("DFS") == 0){
        this->solver = new MatrixSolver(new DFS());
    }
    else if ( nameSolver.compare("BFS") == 0) {
        this->solver = new MatrixSolver(new BFS());
    }
    else if ( nameSolver.compare("Astar") == 0 ) {
        this->solver = new MatrixSolver(new Astar());
    }
    else {
        this->solver = new MatrixSolver(new BestFirstSearch());
    }
    this->SolverName = nameSolver ;
    this->cacheManager = new FileCacheManager<string>();

}
