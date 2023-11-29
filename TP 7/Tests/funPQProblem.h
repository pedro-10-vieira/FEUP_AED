#ifndef SRC_FUNPQP_H_
#define SRC_FUNPQP_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class FunPQProblem{
public:
    FunPQProblem();
    static int minCost(const vector<int> &ropes);
};

#endif