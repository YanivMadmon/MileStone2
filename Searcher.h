//
// Created by shilo on 20.1.2020.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H

#include "Searcheable.h"

template <typename S>
class Searcher {
public:
    virtual S search(Searcheable *problem)= 0;
};


#endif //MILESTONE2_SEARCHER_H
