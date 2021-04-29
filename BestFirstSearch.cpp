//
// Created by shilo on 22.1.2020.
//

#include "BestFirstSearch.h"
#include <vector>
#include <set>
#include "PriorityQueue.h"
string BestFirstSearch::search(Searcheable *problem) {
    State* s1;
    auto *openList = new PriorityQueue();
    openList->queue->push(problem->getInitialState());
    auto *closed = new set<State *>();
    while (!openList->queue->empty()) {
        State *n = popFromOpenList(openList);
        closed->insert(n);
        if (n->equal(problem->getGoalState())) {
            return solution(problem);
        }
        vector<State *>* neighbors = problem->getAllPosibleStates(n);
        //State* s1;
        for (State* s1: *neighbors) {
            //s1=neighbors->at(i);
            if ((closed->find(s1) == closed->end()) && (!openList->conteint(s1))) {
                s1->setFather(n);
                s1->setCost(n->getCost());
                openList->queue->push(s1);
            }
            else {
                if(s1->getCost()>n->getCost()+s1->getValue()) {
                    s1->setCost(n->getCost()+s1->getValue());
                    openList->popState(s1);
                    openList->queue->push(s1);
                    s1->setFather(n);
                }
            }
        }
    }
}

string BestFirstSearch::solution(Searcheable* problem) {
    string sol;
    State* s=problem->getGoalState();
    while(s != problem->getInitialState()) {
        State* iter=s->getFather();
        if(s->getI()>iter->getI()) {
            string temp="Down (" + to_string(s->getCost());
            temp+=") ,"+ sol;
            sol=temp;
        } else if (s->getI()<iter->getI()) {
            string temp="Up (" +to_string(s->getCost());
            temp+=") ,"+ sol;
            sol=temp;
        } else if (s->getJ()>iter->getJ()) {
            string temp="Right (" +to_string(s->getCost());
            temp+=") ,"+ sol;
            sol=temp;
        } else if (s->getJ()<iter->getJ()) {
            string temp="Left (" +to_string(s->getCost());
            temp+=") ,"+ sol;
            sol=temp;
        }
        s=s->getFather();
    }
    string counterNodes = to_string(this->countOfNodes);

    sol=sol.substr(0,sol.size()-2);
   // sol = sol +'\n' + counterNodes;

    return sol;
}
