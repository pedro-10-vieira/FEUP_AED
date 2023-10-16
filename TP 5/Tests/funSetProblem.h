#ifndef SRC_FUNSETP_H_
#define SRC_FUNSETP_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class FunSetProblem{
public:
    FunSetProblem();
    static pair<int,int> pairSum(const vector<int> &values, int sum);
};

#endif