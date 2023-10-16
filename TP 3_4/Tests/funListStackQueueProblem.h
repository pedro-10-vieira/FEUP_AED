#ifndef SRC_FUNSTACKQUEUEP_H_
#define SRC_FUNSTACKQUEUEP_H_

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class FunListStackQueueProblem{
public:
    FunListStackQueueProblem();
    static list<int> removeHigher(list<int> &values, int x);
    static list<pair<int,int>> overlappingIntervals(list<pair<int,int>> values);
    static vector<string> binaryNumbers(int n);
    static vector<int> calculateSpan(vector<int> prices);
    static int knightJumps (int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n);
};

#endif