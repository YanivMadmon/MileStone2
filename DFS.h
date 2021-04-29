//
// Created by yanivmadmon on 1/20/20.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H
#include "Searcher.h"


class DFS:  public Searcher<string> {

    string search(Searcheable *problem);
    string solution(Searcheable* problem);
    int count;

};


#endif //MILESTONE2_DFS_H
