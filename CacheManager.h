//
// Created by yanivmadmon on 1/14/20.
//

#ifndef MILESTONE2_CACHEMANAGER_H
#define MILESTONE2_CACHEMANAGER_H
//ds
#include <stdio.h>
#include <unordered_map>
using namespace std ;
template <typename P, typename S>

class CacheManager {
    unordered_map <P,S> cache;
public:
    virtual void insert (P problem , S solution) =0;
    virtual S get(P problem)=0 ;
    virtual bool ifExistSolution(P problem)=0;
    virtual ~CacheManager(){};
};


#endif //MILESTONE2_CACHEMANAGER_H
