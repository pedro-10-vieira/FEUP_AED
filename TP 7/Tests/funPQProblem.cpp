#include "funPQProblem.h"

FunPQProblem::FunPQProblem() {}


//=============================================================================
// Exercise 2: Minimum Cost
//=============================================================================
// TODO
int FunPQProblem::minCost(const vector<int> &ropes) {
    priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int n : ropes) {
        pq.push(n);
    }
    int c_ropes = 0;
    int res = 0;
    while (pq.size() > 1) {
        for (int i = 2; i > 0; i--) {
            c_ropes += pq.top();
            pq.pop();
        }
        pq.push(c_ropes);
        res += c_ropes;
        c_ropes = 0;
    }
    return res;
}
