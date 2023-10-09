#ifndef _FUNCYCLES_H_
#define _FUNCYCLES_H_

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

class FunWithCycles {
public:
    // Functions to implement - base exercises
    static bool palindrome(const string & s);
    static bool palindromeSentence(const string & s);
    static int nextInterestingNumber(int n, int sum);
    static int winter(const vector<int> & v);

    // Possible auxiliary functions
    static int digitSum(int n);

    // Functions to implement - extra exercises
    static int count(const vector<int> & v, int n);
    static bool hasDuplicates(const vector<int> & v);
    static void removeDuplicates(vector<int> & v);
    static vector<int> merge(const vector<int> & v1, const vector<int> & v2);

    static bool isPrime(int n);
    static vector<int> factorize(int n);
    static vector<int> listPrimes(int n);

};

#endif
