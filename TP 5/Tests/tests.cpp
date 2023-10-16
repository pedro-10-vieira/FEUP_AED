#include <gtest/gtest.h>
#include <benchmark/benchmark.h>
#include "dictionary.h"
#include "funSetProblem.h"
#include <fstream>
#include <algorithm>
#include <random>

using testing::Eq;

//=============================================================================
// Exercise 1: Dictionary
//=============================================================================
// Subexercise 1.1: Create Dictionary
//=============================================================================
TEST(test_1_1, createDictionary) {
    cout<<endl<<"Testing 'createDictionary'"<<endl;
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    Dictionary d1;
    d1.readFile(f);
    f.close();
    set<WordMean> dicT = d1.getWords();
    int n = dicT.size();
    EXPECT_EQ(7,n);
    if (n==7) {
        set<WordMean>::iterator it = dicT.begin();
        it++;
        it++;
        EXPECT_EQ("gato", it->getWord());
    }
}

//=============================================================================
// Subexercise 1.2: Print Dictionary
//=============================================================================
TEST(test_1_2, printDictionary) {
    cout<<endl<<"Testing 'printDictionary'"<<endl;
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    cout << "This test never fails. Check the information on the monitor" << endl;
    Dictionary d1;
    d1.readFile(f);
    f.close();
    d1.print();
}

//=============================================================================
// Subexercise 1.3: Consult Dictionary
//=============================================================================
TEST(test_1_3, consultDictionary) {
    cout<<endl<<"Testing 'consultDictionary'"<<endl;
    ifstream fich;
    fich.open("dic.txt");
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    Dictionary d1;
    d1.readFile(f);
    f.close();
    WordMean prev("",""), next("","");
    EXPECT_EQ("mamifero felino", d1.consult("gato", prev, next));
    string mean1=d1.consult("janela", prev, next);
    EXPECT_EQ("word not found",mean1);
    EXPECT_EQ("ilha", prev.getWord());
    EXPECT_EQ("porto de terra emersa rodeada de agua", prev.getMeaning());
    EXPECT_EQ("macaco", next.getWord());
    EXPECT_EQ("mamifero da ordem dos primatas", next.getMeaning());
}

//=============================================================================
// Subexercise 1.4: Update Dictionary
//=============================================================================
TEST(test_1_4, updateDictionary) {
    cout<<endl<<"Testing 'updateDictionary'"<<endl;
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    Dictionary d1;
    d1.readFile(f);
    f.close();
    WordMean prev("",""), next("","");
    EXPECT_EQ(true,d1.update("morango","fruto vermelho"));
    EXPECT_EQ("fruto vermelho", d1.consult("morango", prev, next));
    EXPECT_EQ(false,d1.update("esquilo","pequeno mamifero roedor de cauda longa"));
    set<WordMean> dicT = d1.getWords();
    int n = dicT.size();
    EXPECT_EQ(8, n);
    if (n == 8) {
        set<WordMean>::iterator it = dicT.begin();
        it++;
        it++;
        EXPECT_EQ("esquilo", it->getWord());
        EXPECT_EQ("pequeno mamifero roedor de cauda longa", d1.consult("esquilo", prev, next));
    }
}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
TEST(test_2, pairSum) {
    pair<int,int> res = FunSetProblem::pairSum({7, 8, 12, 5, 21, 3, 1, 6} , 14);
    bool ok = ((res.first == 8 && res.second ==6) || (res.first == 6 && res.second ==8) );
    EXPECT_EQ(true, ok);
    res = FunSetProblem::pairSum({7, 8, 12, 5, 21, 3, 1, 6} , 16);
    EXPECT_EQ(0, res.first);
    EXPECT_EQ(0,res.second);
    res = FunSetProblem::pairSum({} , 4);
    EXPECT_EQ(0, res.first);
    EXPECT_EQ(0,res.second);
}


//=============================================================================
// BENCHMARK
//=============================================================================
static void BM_Print(benchmark::State& state) {
    for (auto _ : state) {
        Dictionary d1;
        state.PauseTiming();
        // runtime of this will be ignored
        set<WordMean> t;
        for (int i=0;i< state.range(0); i++)
            d1.addWord(WordMean(to_string(i),""));
        state.ResumeTiming();
        // This code gets timed
        d1.print();
    }
    state.SetComplexityN(state.range(0));
}

static void BM_Consult(benchmark::State& state) {
    for (auto _ : state) {
        Dictionary d1;
        state.PauseTiming();
        // runtime of this will be ignored
        set<WordMean> t;
        string val=to_string(state.range(0)/2);
        for (int i=0;i< state.range(0); i++)
            d1.addWord(WordMean(to_string(i), ""));
        state.ResumeTiming();
        // This code gets timed
        WordMean prev("",""), next("","");
        d1.consult(val, prev, next);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_Update(benchmark::State& state) {
    for (auto _ : state) {
        Dictionary d1;
        state.PauseTiming();
        // runtime of this will be ignored
        set<WordMean> t;
        string val=to_string(state.range(0)/2);
        for (int i=0;i< state.range(0); i++)
            d1.addWord(WordMean(to_string(i),""));
        state.ResumeTiming();
        // This code gets timed
        d1.update(val,"xx");
    }
    state.SetComplexityN(state.range(0));
}

static void BM_PairSum(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        vector<int> v;
        for (int i=0;i< state.range(0); i++)
            v.push_back(i);
        std::mt19937 rng(std::time(nullptr));
        std::shuffle(v.begin(), v.end(), rng);
        int val = 2*state.range(0);
        state.ResumeTiming();
        // This code gets timed
        FunSetProblem::pairSum(v,val);
    }
    state.SetComplexityN(state.range(0));
}


//=============================================================================
// Register the functions as a benchmark
//=============================================================================

//NOTE: remove comments from respective BENCHMARKs to run complexity analysis

/*
BENCHMARK(BM_Print)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)-> Range(1<<10,1<<15)
        ->Complexity();
*/

/*
BENCHMARK(BM_Consult)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<15)
        ->Complexity();
*/

/*
BENCHMARK(BM_Update)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_PairSum)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<16)
        ->Complexity();
*/

