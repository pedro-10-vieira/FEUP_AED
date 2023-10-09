#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>
#include <fstream>
#include "funWithComplexity.h"

using testing::Eq;

// Utility functions for reading test cases from files
// (see implementation at the end of this file)
vector<int> readIntVector(string fileName);
int readInt(string fileName);
vector<int> readIntVectorAnd2Int(string fileName, int & k, int &t);


//=============================================================================
// Exercise 4: Analyzing a river
//=============================================================================
TEST(test_4, examples) {
    cout << "Testing 'river'" << endl;

    cout << "  . Examples from the worksheet" << endl;
    EXPECT_EQ(3, FunWithComplexity::river({142,155,147,165,150,112,73}, 3, 150));
    EXPECT_EQ(4, FunWithComplexity::river({5,10,12,10,9,14,5,7,9,11,3,3}, 4, 10));
}

TEST(test_4, others_small) {
    int t, k;

    cout << "  . Other examples - small" << endl;
    vector<int> v1 = readIntVectorAnd2Int("river/input01.txt", t, k);
    EXPECT_EQ(readInt("river/output01.txt"), FunWithComplexity::river(v1, t, k));
    vector<int> v2 = readIntVectorAnd2Int("river/input02.txt", t, k);
    EXPECT_EQ(readInt("river/output02.txt"), FunWithComplexity::river(v2, t, k));
    vector<int> v3 = readIntVectorAnd2Int("river/input03.txt", t, k);
    EXPECT_EQ(readInt("river/output03.txt"), FunWithComplexity::river(v3, t, k));
}


TEST(test_4, others_large) {
    int t, k;

    cout << "  . Other examples - big" << endl;
    vector<int> v1 = readIntVectorAnd2Int("river/input08.txt", t, k);
    EXPECT_EQ(readInt("river/output08.txt"), FunWithComplexity::river(v1, t, k));
    vector<int> v2 = readIntVectorAnd2Int("river/input09.txt", t, k);
    EXPECT_EQ(readInt("river/output09.txt"), FunWithComplexity::river(v2, t, k));
}


//=============================================================================
// Exercise 5: Spiral of Numbers
//=============================================================================
TEST(test_5, examples) {
    cout << "Testing 'spiral'" << endl;

    cout << "  . Examples from the worksheet" << endl;
    pair<int, int> p1 = {-1, -1};
    EXPECT_EQ(p1, FunWithComplexity::spiral(5));
    pair<int, int> p2 = {2, 2};
    EXPECT_EQ(p2, FunWithComplexity::spiral(25));
    pair<int, int> p3 = {1, -1};
    EXPECT_EQ(p3, FunWithComplexity::spiral(3));
}

/*
TEST(test_5, others_small) {
    cout << "  . Other examples - small" << endl;
    pair<int, int> p1 = {-1, 1};
    EXPECT_EQ(p1, FunWithComplexity::spiral(7));
    pair<int, int> p2 = {-2, -2};
    EXPECT_EQ(p2, FunWithComplexity::spiral(17));
    pair<int, int> p3 = {3, -2};
    EXPECT_EQ(p3, FunWithComplexity::spiral(30));
    pair<int, int> p4 = {-11, 7};
    EXPECT_EQ(p4, FunWithComplexity::spiral(503));
}
*/

/*
TEST(test_5, others_large) {
    cout << "  . Other examples - big" << endl;
    pair<int, int> p1 = {499, 499};
    EXPECT_EQ(p1, FunWithComplexity::spiral(998001));
    pair<int, int> p2 = {1682, 15811};
    EXPECT_EQ(p2, FunWithComplexity::spiral(1000000000));
}
*/


//=============================================================================
// Exercise 7: Squared notebook
//=============================================================================
TEST(test_7, examples) {
    cout << "Testing 'gridSum'" << endl;

    cout << "  . Examples from the worksheet" << endl;
    EXPECT_EQ(358, FunWithComplexity::gridSum(13, 51));
    EXPECT_EQ(160, FunWithComplexity::gridSum(5, 31));
    EXPECT_EQ(143, FunWithComplexity::gridSum(28, 44));
    EXPECT_EQ(7480, FunWithComplexity::gridSum(25, 245));
}

/*
TEST(test_7, others_small) {
    cout << "  . Other examples - small" << endl;
    EXPECT_EQ(278, FunWithComplexity::gridSum(131, 147));
    EXPECT_EQ(257, FunWithComplexity::gridSum(22, 67));
    EXPECT_EQ(73, FunWithComplexity::gridSum(18, 31));
    EXPECT_EQ(82, FunWithComplexity::gridSum(12, 30));
    EXPECT_EQ(116, FunWithComplexity::gridSum(116, 116));
    EXPECT_EQ(332, FunWithComplexity::gridSum(157, 175));
    EXPECT_EQ(307, FunWithComplexity::gridSum(89, 116));
    EXPECT_EQ(581, FunWithComplexity::gridSum(48, 123));
    EXPECT_EQ(260, FunWithComplexity::gridSum(49, 82));
    EXPECT_EQ(860, FunWithComplexity::gridSum(105, 185));
}
*/

/*
TEST(test_7, others_large) {
    cout << "  . Other examples - big" << endl;
    EXPECT_EQ(15395874831770160ll, FunWithComplexity::gridSum(275107939, 625086360));
    EXPECT_EQ(27071915783418025ll, FunWithComplexity::gridSum(215299244, 684720683));
    EXPECT_EQ(18717502645457847ll, FunWithComplexity::gridSum(107454973, 491658519));
}
*/


//=============================================================================
// Reading test cases from files
//=============================================================================
vector<int> readIntVector(string fileName) {
    ifstream f(fileName);
    int n;
    f >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        f >> v[i];
    f.close();
    return v;
}

int readInt(string fileName) {
    ifstream f(fileName);
    int n;
    f >> n;
    return n;
}

vector<int> readIntVectorAnd2Int(string fileName, int & k, int &t) {
    ifstream f(fileName);
    int n;
    f >> n >> k >> t;
    vector<int> v(n);
    for (int i=0; i<n; i++)
        f >> v[i];
    f.close();
    return v;
}


//=============================================================================
// BENCHMARK
//=============================================================================
static void BM_River(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        vector<int> data(state.range(0));
        for (int i=0;i< state.range(0); i++)
            data.at(i) = rand() % 400;
        int k = 2 + rand() % 8;
        int t = 100 + rand() % 300;
        state.ResumeTiming();
        // This code gets timed
        FunWithComplexity::river(data, k, t);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_Spiral(benchmark::State& state) {
    for (auto _ : state)
        FunWithComplexity::spiral(state.range(0));

    state.SetComplexityN(state.range(0));
}


//=============================================================================
// Register the functions as a benchmark
//=============================================================================

//NOTE: remove comments from respective BENCHMARKs to run complexity analysis

BENCHMARK(BM_River)
    ->Unit(benchmark::kNanosecond)
    ->DenseRange(1 << 12, 1 << 16, 4096)
    ->Complexity();

/*
BENCHMARK(BM_Spiral)
    ->Unit(benchmark::kNanosecond)
    ->RangeMultiplier(10)->Range(10, 10000000000)
    ->Complexity();
*/
