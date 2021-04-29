//
// Created by shilo on 22.1.2020.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "PriorityQueue.h"
#include <queue>
#include <set>
class BestFirstSearch: public Searcher<string> {
public:
    int countOfNodes=0;
    string search(Searcheable *problem);

    State* popFromOpenList(PriorityQueue* openList) {
        this->countOfNodes++;
        State* s=openList->queue->top();
        openList->queue->pop();
        return s;
    }
    string  solution(Searcheable* problem);
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
