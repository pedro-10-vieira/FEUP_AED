#include "funWithSearch.h"


//=============================================================================
// Exercise 1: Elementary Search
//=============================================================================
// Subexercise 1.1: Linear Search
//=============================================================================
// TODO
int FunWithSearch::searchLinear(const vector<int> &v, int key) {
    for (unsigned i = 0; i < v.size(); i++)
        if (v[i] == key)
            return i; // key found at index i
    return -1; // key not found
}

//=============================================================================
// Subexercise 1.2: Binary Search
//=============================================================================
// TODO
int FunWithSearch::searchBinary(const vector<int> & v, int key) {
    int low = 0, high = (int)v.size() - 1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (key < v[middle]) high = middle - 1;
        else if (key > v[middle]) low = middle + 1;
        else return middle; // key found at index middle
    }
    return -1; // key not found
}

//=============================================================================
// Exercise 2: Facing Sun
//=============================================================================
// TODO
int FunWithSearch::facingSun(const vector<int> & values) {
    int max = values[0];
    int count = 1;
    for (int i : values) {
        if (i > max) {
            max = i;
            count++;
        }
    }
    return count;
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
// TODO
int FunWithSearch::squareR(int num) {
    int low = 0;
    int high = num;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (mid <= num / mid) {
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return low - 1;
}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================
// TODO
int FunWithSearch::minPages(const vector<int> & values, int numSt) {
    return 0;
}
