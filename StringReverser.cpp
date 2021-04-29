//
// Created by yanivmadmon on 1/16/20.
//

#include "StringReverser.h"
string StringReverser:: solve(string problem){
    int len = problem.length();
    string sol;
    sol = "";
   for (int i = len-1 ; i>= 0 ; i--) {
       sol+= problem.at(i);
   }
   return sol;
}