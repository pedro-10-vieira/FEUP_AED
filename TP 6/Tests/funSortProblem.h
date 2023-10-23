#ifndef SRC_FUNSORTP_H_
#define SRC_FUNSORTP_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "piece.h"

using namespace std;

class FunSortProblem{
public:
    FunSortProblem();
    static int minDifference(const vector<unsigned> &values, unsigned nc);
    static unsigned numInversions(vector<int> v);
    static void nutsBolts(vector<Piece> &nuts, vector<Piece> &bolds);
};

#endif
