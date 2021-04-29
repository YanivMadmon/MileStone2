//
// Created by shilo on 24.1.2020.
//

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H
#include "Searcher.h"
#include "PriorityQueue.h"
#include "PriorityQueueAstar.h"
#include <queue>
#include <set>

class Astar: public Searcher<string> {
public:
    int countOfNodes=0;
    string search(Searcheable *problem);
    State* popFromOpenList(PriorityQueueAstar* openList) {
        this->countOfNodes++;
        State* s=openList->queueAstar->top();
        openList->queueAstar->pop();
        return s;
    }
    string  solution(Searcheable* problem);
    int heuristic(State* s,Searcheable* problem);
};


#endif //MILESTONE2_ASTAR_H
