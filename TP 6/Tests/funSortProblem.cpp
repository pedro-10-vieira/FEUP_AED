#include "funSortProblem.h"

FunSortProblem::FunSortProblem() {}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if (values.size() < nc) {
        return -1;
    }
    vector<unsigned> chocolates = values;
    sort(chocolates.begin(), chocolates.end());
    int min = INT_MAX;
    for (int i = 0; i <= chocolates.size() - nc; i++) {
        if (chocolates[i + nc - 1] - chocolates[i] < min) {
            min = chocolates[i + nc - 1] - chocolates[i];
        }
    }
    return min;
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
//TODO
unsigned FunSortProblem::numInversions(vector <int> v) {
    return 0;
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
// TODO
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
}
