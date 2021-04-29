//
// Created by shilo on 21.1.2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H
#include <iostream>
#include <utility>
using namespace std;
class State {
 int i;
 int j;
 int cost;
 int value;
 int hyoristicCost;
 State* father;
public:
    State(int i , int j , int value){this->i = i ; this->j = j ; this->value = value; this->cost = value;this->hyoristicCost=0;}
    int getI(){return i;}
    int getJ(){return j;}
    int getValue()const{return value;}
    int getCost()const{return cost;}
    bool equal(State* s) {
        if((s->getI()==this->getI())&&s->getJ()==this->getJ()) {
            return true;
        }
        return false;
    }
    void setFather(State* s) {this->father=s;}
    State* getFather() {return this->father;}
    void setCost(int c) {
        cost+=c;
    }
    int getHyoristic() const {
        return this->hyoristicCost;
    }

    void setHyorictic(int h) {
        this->hyoristicCost=h;
    };
    class myComparator
    {
    public:
        int operator() (const State* s1, const State* s2)
        {
            return s1->getCost() > s2->getCost();
        }
    };

    class AstarComparator
    {
    public:
        int operator() (const State* s1, const State* s2)
        {
            return s1->getHyoristic() > s2->getHyoristic();
        }
    };
};


#endif //MILESTONE2_STATE_H
