#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    set<int> sumPair;
    for (int i : values) {
        if (sumPair.find(sum - i) != sumPair.end()) {
            return make_pair(i, sum - i);
        }
        else {
            sumPair.insert(i);
        }
    }
    return make_pair(0,0);
}
