//
// Created by yanivmadmon on 1/23/20.
//

#include "BFS.h"
#include <vector>
#include <list>

using namespace std;

string BFS:: search(Searcheable *problem){
    list<State*>* visitQueue = new list<State*>();
    visitQueue->push_front(problem->getInitialState());
    list<State*>* stackQueue = new list<State*>();
    vector<State*>*  neighbors;
    bool eq = false ;
    this->count = 0;
    while(true){
        State *n = visitQueue->front();
        neighbors = problem->getAllPosibleStates(n);
        for (State* s : *neighbors){
            for (State* s2 : *visitQueue){
                if  (s->equal(s2)){
                    eq = true;
                }
            }
            for (State* s2 : *stackQueue){
                if  (s->equal(s2)){
                    eq = true;
                }
            }
            if (!eq) {
                stackQueue->push_back(s);
                s->setFather(n);
                s->setCost(n->getCost());
            }
            eq = false;
        }
        this->count++;
        if (stackQueue->front() == nullptr){
            return "No way";
        }
        State* next = stackQueue->front();
        visitQueue->push_front(next);
        if(next->equal(problem->getGoalState())){
            return solution(problem);
        }
        stackQueue->pop_front();
    }
}
string BFS::solution(Searcheable* problem) {
    string sol="";
    State* s=problem->getGoalState();
    while(!(s->equal(problem->getInitialState()))) {
        State* iter=s->getFather();
        if(s->getI()>iter->getI()) {
            string strCost = to_string(s->getCost());
            string temp="Down (" +strCost;
            temp+=") ,"+ sol;
            sol=temp;
        } else if (s->getI()<iter->getI()) {
            string strCost = to_string(s->getCost());
            string temp="Up (" +strCost;
            temp+=") ,"+ sol;
            sol=temp;
        } else if (s->getJ()>iter->getJ()) {
            string strCost = to_string(s->getCost());
            string temp="Right (" +strCost;
            temp+=") ,"+ sol;
            sol=temp;
        } else if (s->getJ()<iter->getJ()) {
            string strCost = to_string(s->getCost());
            string temp="Left (" +strCost;
            temp+=") ,"+ sol;
            sol=temp;
        }
        s=s->getFather();
    }
    string counterNodes = to_string(this->count);
    sol.erase(sol.size()-2 , 2);
   // sol = sol +'\n' + counterNodes;
    return sol;
}

