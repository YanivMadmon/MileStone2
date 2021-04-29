//
// Created by shilo on 22.1.2020.
//

#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include <queue>
#include "State.h"
#include <functional>

using namespace std;
class PriorityQueue {

public:
    priority_queue <State*, vector<State*>, typename State::myComparator > *queue;
    priority_queue <State*, vector<State*>, typename State::AstarComparator > *queueAstar;
    PriorityQueue() {
        queue = new priority_queue <State*, vector<State*>, typename State::myComparator >();
    }
    PriorityQueue(int) {
        queueAstar = new priority_queue <State*, vector<State*>, typename State::AstarComparator >();
    }

    bool conteint(State *s) {

        vector<State *> tempArr;
        while (!queue->empty()) {
            State *current = queue->top();
            tempArr.push_back(current);
            queue->pop();
            if (s->equal(current)) {
                for (State *s:tempArr) {
                    queue->push(s);
                }
                return true;
            }

        }
        State* s1;
        for (int i=0; i<tempArr.size() ;i++) {
            queue->push(tempArr[i]);
        }
        return false;
    }

    void popState(State *s) {

        vector<State *> tempArr;
        while (!queue->empty()) {
            State *current = queue->top();
            queue->pop();
            if (s->equal(current)) {
                if(!tempArr.empty()) {
                    for (State *s:tempArr) {
                        queue->push(s);
                        return;
                    }
                }
            }
            tempArr.push_back(current);
        }
    }
};


#endif //MILESTONE2_PRIORITYQUEUE_H
