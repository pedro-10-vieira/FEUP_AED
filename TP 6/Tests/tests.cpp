#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>
#include <algorithm>
#include <random>
#include "funWithSearch.h"
#include "funSortProblem.h"

using testing::Eq;


//=============================================================================
// Exercise 1: Elementary Search
//=============================================================================
// Subexercise 1.1: Linear Search
//=============================================================================
TEST(test_1_1, searchLinear) {
    cout << "Testing Linear 'search'" << endl;
    EXPECT_EQ(0, FunWithSearch::searchLinear({2,3,5,7,8}, 2));
    EXPECT_EQ(4, FunWithSearch::searchLinear({2,3,5,7,8}, 8));
    EXPECT_EQ(3, FunWithSearch::searchLinear({2,3,5,7,8}, 7));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,8}, 1));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,8}, 10));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,8}, 6));

    EXPECT_EQ(9, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 18));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 20));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 1));
    EXPECT_EQ(1, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 3));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 4));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 17));
    EXPECT_EQ(3, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 7));
    EXPECT_EQ(2, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 5));
    EXPECT_EQ(5, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 11));
    EXPECT_EQ(-1, FunWithSearch::searchLinear({2,3,5,7,10,11,12,14,16,18}, 13));
}

//=============================================================================
// Subexercise 1.2: Binary Search
//=============================================================================
TEST(test_1_2, searchBinary) {
cout << "Testing Binary 'search'" << endl;
    EXPECT_EQ(0, FunWithSearch::searchBinary({2,3,5,7,8}, 2));
    EXPECT_EQ(4, FunWithSearch::searchBinary({2,3,5,7,8}, 8));
    EXPECT_EQ(3, FunWithSearch::searchBinary({2,3,5,7,8}, 7));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,8}, 1));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,8}, 10));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,8}, 6));
    
    EXPECT_EQ(9, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 18));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 20));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 1));
    EXPECT_EQ(1, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 3));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 4));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 17));
    EXPECT_EQ(3, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 7));
    EXPECT_EQ(2, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 5));
    EXPECT_EQ(5, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 11));
    EXPECT_EQ(-1, FunWithSearch::searchBinary({2,3,5,7,10,11,12,14,16,18}, 13));
}


//=============================================================================
// Exercise 2: Facing Sun
//=============================================================================
TEST(test_2, facingsun){
    EXPECT_EQ(3,FunWithSearch::facingSun({7, 4, 8, 2, 9}));
    EXPECT_EQ(4,FunWithSearch::facingSun({2, 3, 4, 5}));
}


//=============================================================================
// Exercise 3: Square Root
//=============================================================================
TEST(test_3, squareR){
    EXPECT_EQ(2, FunWithSearch::squareR(4));
    EXPECT_EQ(2, FunWithSearch::squareR(5));
}


//=============================================================================
// Exercise 4: Min Difference
//=============================================================================
TEST(test_5, minDifference){
    EXPECT_EQ(6,FunSortProblem::minDifference({3,4,1,9,56,7,9,12}, 5));
    EXPECT_EQ(-1,FunSortProblem::minDifference({3,4,1,9,56,7}, 7));
    EXPECT_EQ(11,FunSortProblem::minDifference({3,4,1,9,12,7}, 6));
    EXPECT_EQ(2,FunSortProblem::minDifference({7, 3, 2, 4, 9, 12, 56}, 3));
}


//=============================================================================
// Exercise 5: MinPages (extra)
//=============================================================================

TEST(test_6, minPages){
    EXPECT_EQ(113, FunWithSearch::minPages({12, 34, 67, 90},2));
    EXPECT_EQ(32, FunWithSearch::minPages({15, 17, 20},2));
}


//=============================================================================
// Exercise 6: Num Inversions (extra)
//=============================================================================
TEST(test_7, numInversions){
    vector<int> v1 = {10,50,20,40,30};
    EXPECT_EQ(4,FunSortProblem::numInversions(v1));
    vector<int> v2 = {2, 4, 1, 3, 5};
    EXPECT_EQ(3,FunSortProblem::numInversions(v2));
    vector<int> v3 = {10,20,30,40,50,60,70};
    EXPECT_EQ(0,FunSortProblem::numInversions(v3));
}


//=============================================================================
// Exercise 7: Nuts and Bolts (extra)
//=============================================================================
TEST(test_8, nutsBolts){
    vector<Piece> nuts = {Piece("n1",10),Piece("n7",9),Piece("n4",11),Piece("n2",8),Piece("n5",7),Piece("n8",12), Piece("n9",15)};
    vector<Piece> bolts = { Piece("b5",7), Piece("b8",12), Piece("b1",10), Piece("b2",8), Piece("b9",15), Piece("b4",11), Piece("b7",9)};
    FunSortProblem::nutsBolts(nuts, bolts);
    EXPECT_EQ(7, nuts.size());
    EXPECT_EQ(7, bolts.size());
    for (unsigned i=0; i<7; i++) {
        EXPECT_EQ(true,nuts[i].getDiameter() == bolts[i].getDiameter());
    }
}


//=============================================================================
// BENCHMARK
//=============================================================================
static void BM_SearchLinear(benchmark::State& state) {
    vector<int> v(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (int i=0; i< state.range(0); i++)
            v.at(i) = i;
        int k = (int) rand()%state.range(0);
        state.ResumeTiming();
        // This code gets timed
        FunWithSearch::searchLinear(v,k);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_SearchBinary(benchmark::State& state) {
    vector<int> v(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (int i=0; i< state.range(0); i++)
            v.at(i) = i;
        int k = (int) rand()%state.range(0);
        state.ResumeTiming();
        // This code gets timed
        FunWithSearch::searchBinary(v,k);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_FacingSun(benchmark::State& state) {
    vector<int> v(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (int i=0; i< state.range(0); i++)
            v.at(i) = rand()%state.range(0);
        state.ResumeTiming();
        // This code gets timed
        FunWithSearch::facingSun(v);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_MinDifference(benchmark::State& state) {
    vector<unsigned int> v(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (int i=0; i< state.range(0); i++)
            v.at(i) = rand()%state.range(0);
        int nc = rand()%state.range(0);
        state.ResumeTiming();
        // This code gets timed
        FunSortProblem::minDifference(v, nc);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_NumInversions(benchmark::State& state) {
    vector<int> v(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (int i=0; i< state.range(0); i++)
            v.at(i) = rand()%state.range(0);
        state.ResumeTiming();
        // This code gets timed
        FunSortProblem::numInversions(v);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_NutsBolts(benchmark::State& state) {
    auto rng = std::default_random_engine {};
    vector<int> rnd(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (int i=0; i< state.range(0); i++)
            rnd.at(i) = i;
        vector<int> rnd2 = rnd;
        std::shuffle(std::begin(rnd), std::end(rnd), rng);
        std::shuffle(std::begin(rnd2), std::end(rnd2), rng);
        vector<Piece> nuts = {};
        vector<Piece> bolts = {};
        for (int i=0; i< state.range(0); i++) {
            nuts.emplace_back(Piece("n" + std::to_string(rnd.at(i)), rnd2.at(i)));
        }
        std::shuffle(std::begin(rnd), std::end(rnd), rng);
        std::shuffle(std::begin(rnd2), std::end(rnd2), rng);
        for (int i=0; i< state.range(0); i++) {
            bolts.emplace_back(Piece("n" + std::to_string(rnd.at(i)), rnd2.at(i)));
        }
        state.ResumeTiming();
        // This code gets timed
        FunSortProblem::nutsBolts(nuts, bolts);
    }
    state.SetComplexityN(state.range(0));
}


//=============================================================================
// Register the functions as a benchmark
//=============================================================================

//NOTE: remove comments from respective BENCHMARKs to run complexity analysis

/*
BENCHMARK(BM_SearchLinear)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<5, 1<<16)->Iterations(1<<15)
        ->Complexity();
*/

/*
BENCHMARK(BM_SearchBinary)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<5, 1<<16)->Iterations(1<<15)
        ->Complexity();
*/

/*
BENCHMARK(BM_FacingSun)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(4)->Range(1<<5, 1<<15)
        ->Complexity();
*/

/*
BENCHMARK(BM_MinDifference)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<2, 1<<10)
        ->Complexity();
*/

/*
BENCHMARK(BM_NumInversions)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<2, 1<<10)
        ->Complexity();
*/

/*
BENCHMARK(BM_NutsBolts)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<4, 1<<12)
        ->Complexity();
*/
