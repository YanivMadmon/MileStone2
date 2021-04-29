//
// Created by yanivmadmon on 1/14/20.
//

#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H

#include <stdio.h>
#include <unordered_map>
#include <fstream>
#include <mutex>
#include "CacheManager.h"
static std::mutex mtx;

using namespace std;

template<typename S>
class FileCacheManager : public CacheManager<string , S> {

public:
    void insert(string problem, S solution) {
        string str = hashString(problem);
        std::ofstream toFile(str,ios::binary);
        toFile << solution << endl;
        toFile.close();
    }


    string get(string problem) {
        string solutionName = hashString(problem);
        ifstream f;
        f.open(solutionName, ios::binary);
        if (f.fail()) {
            throw ("key not exist in files");
        }
        string solu = {};
        solu.assign( (std::istreambuf_iterator<char>(f) ),
                      (std::istreambuf_iterator<char>()    ) );
        //getline(f,solu);
        f.close();
        return solu;
    }

    bool ifExistSolution(string problem) {
        string s = hashString(problem);
        std::ifstream f(s, std::ios::binary);
        if (f.fail()) {
            return false;
        }
        return true;
    }

    string hashString(string str) {
        hash<string> hasher;
        size_t hash = hasher(str);
        string str1 = to_string(hash);
        return str1;
    };
};


#endif //MILESTONE2_FILECACHEMANAGER_H