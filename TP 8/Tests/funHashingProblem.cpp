#include "funHashingProblem.h"

FunHashingProblem::FunHashingProblem() {}


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
// TODO
vector<int> FunHashingProblem::findDuplicates(const vector<int>& values, int k) {
    vector<int> res;
    unordered_set<int> us;
    for (int i = 0; i < values.size(); i++) {
        if (i > k) {
            us.erase(values[i - k - 1]);
        }
        if (us.find(values[i]) != us.end()) {
            res.push_back(values[i]);
        }
        else {
            us.insert(values[i]);
        }
    }
    return res;
}
