#include "funWithCycles.h"

//=============================================================================
// Exercise 1: Palindromes
//=============================================================================
// TODO
bool FunWithCycles::palindrome(const std::string & s) {
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}


//=============================================================================
// Exercise 2: Palindrome Sentences
//=============================================================================
// TODO
bool FunWithCycles::palindromeSentence(const std::string & s) {
    string res;
    for (char i : s) {
        if (!(isalpha(i))) {
            continue;
        };
        res.push_back(tolower(i));
    }
    return palindrome(res);
}


//=============================================================================
// Exercise 3: Interesting Numbers
//=============================================================================
// TODO
int FunWithCycles::nextInterestingNumber(int n, int sum) {
    n += 1;
    int res = digitSum(n);
    while (res != sum) {
        n += 1;
        res = digitSum(n);
    }
    return n;
}

// This auxiliary function should return the sum of the digits of n
// TODO
int FunWithCycles::digitSum(int n) {
    string num = to_string(n);
    int res = 0;
    for (char i : num) {
        res += i - '0';
    }
    return res;
}


//=============================================================================
// Exercise 4: Winter is coming
//=============================================================================
// TODO
int FunWithCycles::winter(const vector<int> & v) {
    int seq = 0;
    int res = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] - v[i - 1] < 0) {
            seq ++;
        }
        else if (seq > res) {
            res = seq;
            seq = 0;
        }
        else {
            seq = 0;
        }
    }
    return max(res, seq);
}


//=============================================================================
// Exercise 5: Playing with vectors
//=============================================================================

// a) count
// TODO
int FunWithCycles::count(const vector<int> & v, int n) {
    int res = 0;
    for (int i : v) {
        if (i == n) {
            res++;
        }
    }
    return res;
}

// b) hasDuplicates
// TODO
bool FunWithCycles::hasDuplicates(const vector<int> & v) {
    for (int i = 0; i < v.size(); i++) {
        if (count(v, v[i]) > 1) {
            return true;
        }
    }
    return false;
}

// c) removeDuplicates
// TODO
void FunWithCycles::removeDuplicates(vector<int> & v) {
    if (hasDuplicates(v)) {
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                while (v[j] == v[i] && j < v.size()) {
                    v.erase(v.begin() + j);
                }
            }
        }
    }
}

// d) merge
// TODO
vector<int> FunWithCycles::merge(const vector<int> & v1, const vector<int> & v2) {
    vector<int> ans;
    for (int i : v1) {
        ans.push_back(i);
    }
    for (int i : v2) {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}


//=============================================================================
// Exercise 6: Playing with prime numbers
//=============================================================================

// a) isPrime
// TODO
bool FunWithCycles::isPrime(int n) {
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// b) factorize
// TODO
vector<int> FunWithCycles::factorize(int n) {
    if (isPrime(n)) {
        return {1, n};
    }
    vector<int> ans;
    while (n != 1) {
        for (int i = 2; i <= n / 2; i++) {
            if (isPrime(i)) {
                if (n % i == 0) {
                    ans.push_back(i);
                    n /= i;
                }
            }
        }
    }
    return ans;
}

// c) listPrimes
// TODO
vector<int> FunWithCycles::listPrimes(int n) {
    vector<int> ans;
    return ans;
}
