#ifndef _FUNSEARCH_H_
#define _FUNSEARCH_H_

#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

class FunWithSearch {
public:
    static int searchLinear(const vector<int> & v, int key);
    static int searchBinary(const vector<int> & v, int key);
    static int facingSun(const vector<int> & values);
    static int squareR(int num);
    static int minPages(const vector<int> & values, int numSt);};

#endif
