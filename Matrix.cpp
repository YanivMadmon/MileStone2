//
// Created by yanivmadmon on 1/21/20.
//

#include "Matrix.h"
Matrix:: Matrix(vector<string>* matrixString) {
    int sizeM = matrixString->size() -2 ;
    this->n = sizeM-1 ;
    this->MatrixStates = new vector<vector<State*>>;
    vector<State*> line ;
    string value;
    int find;
    int findNext = -1;
    for ( int i= 0 ; i< sizeM ; i++) {
        line.clear();
        for (int j = 0; j < sizeM; j++) {
            find = findNext+1;
            if ( j == sizeM -1){

                findNext = matrixString->at(i).find("\n", find);
            }
            else{
                findNext = matrixString->at(i).find(",", find);
            }
            value = matrixString->at(i).substr(find , findNext-find);
            State *tempState = new State(i, j, stoi(value));
            line.push_back(tempState);
        }
        this->MatrixStates->push_back(line);
    }

    string enterStr = matrixString->at(n+1);
    string exitStr = matrixString->at(n+2);

    find = enterStr.find(",", 0);
    int p = enterStr.size();
    int iEnter = stoi(enterStr.substr(0,find));
    int jEnter = stoi(enterStr.substr(find+1,(enterStr.size()-find-1)));

    find = exitStr.find(",", 0);
    int iExit = stoi(exitStr.substr(0,find));
    int jExit = stoi(exitStr.substr(find+1, (exitStr.size()-find-1)));
    this->enter = this->MatrixStates->at(iEnter).at(jEnter);
    this->exit = this->MatrixStates->at(iExit).at(jExit);

}
State* Matrix:: getInitialState(){
    return this->enter;
}
State* Matrix:: getGoalState() {
    return this->exit;
}
vector<State*>*  Matrix:: getAllPosibleStates(State* s) {

    vector<State*>* PosibleStates = new vector<State*> ;
    int i = s->getI() ;
    int j = s->getJ() ;
    if  ( i != 0 ){
        if(this->MatrixStates->at(i-1).at(j)->getValue() != -1) {
            PosibleStates->push_back(this->MatrixStates->at(i - 1).at(j)); // up
        }
    }
    if( i != this->n){
        if(this->MatrixStates->at(i+1).at(j)->getValue() != -1) {
            PosibleStates->push_back(this->MatrixStates->at(i + 1).at(j)); // down
        }
    }
    if  ( j != 0 ){
        if(this->MatrixStates->at(i).at(j-1)->getValue() != -1) {
            PosibleStates->push_back(this->MatrixStates->at(i).at(j - 1)); // left
        }
    }
    if( j != this->n){
        if(this->MatrixStates->at(i).at(j+1)->getValue() != -1) {
            PosibleStates->push_back(this->MatrixStates->at(i).at(j + 1)); // right
        }
    }
    return PosibleStates;
}
