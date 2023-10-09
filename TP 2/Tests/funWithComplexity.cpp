#include "funWithComplexity.h"

//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================
// TODO
int FunWithComplexity::river(const vector<int> & v, int k, int t) {
    int count = 0;
    int regions = 0;
    int lowerBound = 0;
    int upperBound = k - 1;
    for (int i = 0; i < k; i++) {
        if (v[i] >= t) {
            count++;
        }
    }
    if (count >= (k / 2 + k % 2)) {
        regions++;
    }
    lowerBound++;
    upperBound++;
    while (upperBound < v.size()) {
        if (v[lowerBound - 1] >= t) {
            count--;
        }
        if (v[upperBound] >= t) {
            count++;
        }
        if (count >= (k / 2 + k % 2)) {
            regions++;
        }
        lowerBound++;
        upperBound++;
    }
    return regions;
}

//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
// TODO
pair<int, int> FunWithComplexity::spiral(int n) {
    pair<int, int> ans = {0, 0};
    return ans;
}


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
// TODO
long long FunWithComplexity::gridSum(int a, int b) {
    return 0;
}