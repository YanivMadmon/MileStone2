//
// Created by shilo on 13.1.2020.
//

#include "MyTestClientHandler.h"
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;

void MyTestClientHandler:: handleClient(int client_socket)
{//ds
    string arr[40] ;
    char buffer[1024] = {0};
    string str="";
    while(true) {
        int valread = read(client_socket, buffer, 1048);
        str = "";
            for (char c:buffer) {
                if (c == '\n') {
                    break;
                }
                str += c;
            }
            if (str == "end") {
                break;
            }
            if (cacheManager->ifExistSolution(str)) {
                string strSol = cacheManager->get(str);
                int n = strSol.length();
                char char_array[n + 1];
                strcpy(char_array, strSol.c_str());
                send(client_socket, char_array, strlen(char_array), 0);
            } else {
                if (!this->cacheManager->ifExistSolution(str)){
                    throw "Error";
                }
                string strSol = solver->solve(str);
                cacheManager->insert(str,strSol);
                int n = strSol.length();
                char char_array[n + 1];
                strcpy(char_array, strSol.c_str());
                send(client_socket, char_array, strlen(char_array), 0);
            }
    }

}