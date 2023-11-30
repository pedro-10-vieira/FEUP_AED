#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>
#include "jackpot.h"
#include "funHashingProblem.h"

using testing::Eq;


//=============================================================================
// Exercise 1: Find Duplicates
//=============================================================================
TEST(test_1, a_FindDuplicates) {
    vector<int> v1 = { 5, 6, 8, 2, 4, 6, 9 };
    EXPECT_EQ(7, v1.size());
    EXPECT_EQ(5, v1[0]);
    EXPECT_EQ(9, v1[6]);

    vector<int> res1 = FunHashingProblem::findDuplicates(v1, 4);
    EXPECT_EQ(1, res1.size());
    EXPECT_EQ(6, res1[0]);

    vector<int> res2 = FunHashingProblem::findDuplicates(v1, 2);
    EXPECT_EQ(0, res2.size());

    vector<int> v2 = { 1, 2, 3, 2, 1 };
    EXPECT_EQ(5, v2.size());
    vector<int> res3 = FunHashingProblem::findDuplicates(v2, 7);
    EXPECT_EQ(2, res3.size());
    EXPECT_EQ(2, res3[0]);
    EXPECT_EQ(1, res3[1]);
}


//=============================================================================
// Exercise 2: Jackpot
//=============================================================================
// Subexercise 2.1: Add Bet
//=============================================================================
TEST(test_2_1, addBet){
    Jackpot j;

    vector<int> vals = {30, 45, 22, 17, 8, 15};
    Bet b1(vals, "Rui");

    vals.clear(); vals = {3, 44, 22, 15, 34, 20};
    Bet b2 (vals, "Maria");

    j.addBet(b1);
    j.addBet(b2);
    EXPECT_EQ(2,j.getNumBets());

    vals.clear(); vals = {41, 32, 12, 15, 28, 4};
    Bet b3(vals, "Joao");
    j. addBet (b3);

    Bet b4(vals, "Joao");
    j.addBet(b4);
    EXPECT_EQ(3,j.getNumBets());
}

//=============================================================================
// Subexercise 2.2: Bets in Number
//=============================================================================
TEST(test_2_2, betsInNumber){
    Jackpot j;
    vector<int> vals = {30, 45, 22, 17, 8, 15};
    Bet b1(vals, "Rui");

    vals.clear(); vals = {3, 44, 22, 15, 34, 20};
    Bet b2 (vals, "Maria");

    vals.clear(); vals = {41, 32, 12, 15, 28, 4};
    Bet b3(vals, "Joao");

    j.addBet(b1);
    j.addBet(b2);
    j.addBet(b3);
    EXPECT_EQ(3,j.getNumBets());

    EXPECT_EQ(2,j.betsInNumber(22));
    EXPECT_EQ(1,j.betsInNumber(4));
    EXPECT_EQ(0,j.betsInNumber(5));
}

//=============================================================================
// Subexercise 2.3: Drawn Bets
//=============================================================================
TEST(test_2_3, drawnBets){
    Jackpot j;
    vector<int> vals = {30, 45, 22, 17, 8, 18};
    Bet b1(vals, "Rui");

    vals.clear(); vals = {3, 4, 22, 15, 34, 20};
    Bet b2(vals, "Maria");

    vals.clear(); vals = {45, 32, 18, 15, 8, 33};
    Bet b3(vals, "Joao");

    j.addBet(b1);
    j.addBet(b2);
    j.addBet(b3);
    EXPECT_EQ(3,j.getNumBets());

    vector<int> draw = {44,18,22,33,45,8};
    vector<string> res = j.drawnBets(draw);
    EXPECT_EQ(2,res.size());
    vector<string>::iterator it= find(res.begin(), res.end(),"Rui");
    EXPECT_EQ(false, it==res.end());
    it= find(res.begin(), res.end(),"Joao");
    EXPECT_EQ(false, it==res.end());
    it= find(res.begin(), res.end(),"Maria");
    EXPECT_EQ(true, it==res.end());
}


//=============================================================================
// BENCHMARK
//=============================================================================
static void BM_FindDuplicates(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        vector<int> v;
        for (long i=0;i< state.range(0); i++)
            v.push_back (i%10+3);
        state.ResumeTiming();
        // This code gets timed
        FunHashingProblem::findDuplicates(v,4);
    }
    state.SetComplexityN(state.range(0));
}


//=============================================================================
// Register the functions as a benchmark
//=============================================================================

//NOTE: remove comments from respective BENCHMARKs to run complexity analysis

/*
BENCHMARK(BM_FindDuplicates)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/
