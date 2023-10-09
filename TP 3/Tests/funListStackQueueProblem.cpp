#include "funListStackQueueProblem.h"
#include "cell.h"

FunListStackQueueProblem::FunListStackQueueProblem() {}


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
// TODO
list<int> FunListStackQueueProblem::removeHigher(list<int> &values, int x) {
    list<int> res; //final list
    auto it = values.begin();
    while (it != values.end()) {
        if (*it > x) {
            res.push_back(*it); //push back to the final list all the members higher than x
            it = values.erase(it); //delete them
        }
        else {
            it++; //advance to the next element if the condition doesn't occur
        }
    }
    return res;
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
//TODO
list<pair<int,int>> FunListStackQueueProblem::overlappingIntervals(list<pair<int,int>> values) {
    values.sort();
    auto it = values.begin();
    list<pair<int,int>> res = {*it}; //the final list has temporarily the 1st element from the original one
    for (it++; it != values.end(); it++) {
        if (it->first <= res.back().second) { //if there is an interval overlap
            res.back().second = max(it->second, res.back().second); //merge them
        }
        else {
            res.push_back(*it); //if there's not an overlap push back the original interval to the final list
        }
    }
    return res;
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
// TODO
vector<string> FunListStackQueueProblem::binaryNumbers(int n) {
    vector<string> res;
    queue<string> binaries;
    binaries.emplace("1");
    while (n--) {
        res.push_back(binaries.front());
        binaries.push(binaries.front() + "0");
        binaries.push(binaries.front() + "1");
        binaries.pop();
    }
    return res;
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
//TODO
vector<int> FunListStackQueueProblem::calculateSpan(vector<int> prices) {
    vector<int> res;
    return res;
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
//TODO
int FunListStackQueueProblem::knightJumps(int initialPosx, int initialPosy, int targetPosx, int targetPosy, int n) {
    return -1;
}
