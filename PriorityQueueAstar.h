//
// Created by shilo on 24.1.2020.
//

#ifndef MILESTONE2_PRIORITYQUEUEASTAR_H
#define MILESTONE2_PRIORITYQUEUEASTAR_H


#include "State.h"
#include <queue>

#include <functional>
class PriorityQueueAstar {

public:
    priority_queue <State*, vector<State*>, typename State::AstarComparator > *queueAstar;
    PriorityQueueAstar() {
        queueAstar = new priority_queue <State*, vector<State*>, typename State::AstarComparator >();
    }

    bool conteint(State *s) {

        vector<State *> tempArr;
        while (!queueAstar->empty()) {
            State *current = queueAstar->top();
            tempArr.push_back(current);
            queueAstar->pop();
            if (s->equal(current)) {
                for (State *s:tempArr) {
                    queueAstar->push(s);
                }
                return true;
            }

        }
        State* s1;
        for (int i=0; i<tempArr.size() ;i++) {
            queueAstar->push(tempArr[i]);
        }
        return false;
    }

    void popState(State *s) {

        vector<State *> tempArr;
        while (!queueAstar->empty()) {
            State *current = queueAstar->top();
            queueAstar->pop();
            if (s->equal(current)) {
                if(!tempArr.empty()) {
                    for (State *s:tempArr) {
                        queueAstar->push(s);
                        return;
                    }
                }
            }
            tempArr.push_back(current);
        }
    }
};


#endif //MILESTONE2_PRIORITYQUEUEASTAR_H
