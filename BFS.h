//
// Created by yanivmadmon on 1/23/20.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H
#include "Searcher.h"


class BFS: public Searcher<string> {
    string search(Searcheable *problem);
    string solution(Searcheable* problem);
    int count;
};


#endif //MILESTONE2_BFS_H
