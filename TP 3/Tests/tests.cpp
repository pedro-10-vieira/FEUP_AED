#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>
#include "stackExt.h"
#include "kid.h"
#include "game.h"
#include "funListStackQueueProblem.h"
#include <string>

using testing::Eq;


//=============================================================================
// Exercise 1: Remove Higher
//=============================================================================
TEST(test_1, removeHiger) {
    cout << endl << "Testing 'removeHigher''" << endl;
    list<int> values1 = {7,8,12,5,2,3,5,6};
    list<int> res = FunListStackQueueProblem::removeHigher(values1,5);
    EXPECT_EQ(4, res.size());
    EXPECT_EQ(4, values1.size());
    if (res.size()==4) {
        list<int>::iterator it = res.begin();
        EXPECT_EQ(7,*it); it++;
        EXPECT_EQ(8,*it); it++;
        EXPECT_EQ(12,*it); it++;
        EXPECT_EQ(6,*it);
    }
    if (values1.size()==4) {
        list<int>::iterator it = values1.begin();
        EXPECT_EQ(5,*it); it++;
        EXPECT_EQ(2,*it); it++;
        EXPECT_EQ(3,*it); it++;
        EXPECT_EQ(5,*it);
    }
}


//=============================================================================
// Exercise 2: Overlapping Intervals
//=============================================================================
TEST(test_2, overlappingIntervals) {
    cout << endl << "Testing 'overlappingIntervals''" << endl;
    list<pair<int, int>> values1;
    values1.push_back(make_pair(2, 4));
    values1.push_back(make_pair(6, 8));
    values1.push_back(make_pair(1, 3));
    values1.push_back(make_pair(9, 10));
    list<pair<int,int>> res = FunListStackQueueProblem::overlappingIntervals(values1);
    EXPECT_EQ(3, res.size());
    if (res.size()==3) {
        EXPECT_NE(res.end(),find_if(res.begin(),res.end(), [&](const pair<int,int>& e) { return e == make_pair(6,8); }));
        EXPECT_NE(res.end(),find_if(res.begin(),res.end(), [&](const pair<int,int>& e) { return e == make_pair(1,4); }));
        EXPECT_NE(res.end(),find_if(res.begin(),res.end(), [&](const pair<int,int>& e) { return e == make_pair(9,10); }));
    }

    list<pair<int, int>> values2;
    values2.push_back(make_pair(6, 8));
    values2.push_back(make_pair(1, 9));
    values2.push_back(make_pair(2, 4));
    values2.push_back(make_pair(4, 7));
    res = FunListStackQueueProblem::overlappingIntervals(values2);
    EXPECT_EQ(1, res.size());
    if (res.size()==1) {
        EXPECT_NE(res.end(),find_if(res.begin(),res.end(), [&](const pair<int,int>& e) { return e == make_pair(1,9); }));
    }

    list<pair<int, int>> values3;
    values3.push_back(make_pair(2, 7));
    values3.push_back(make_pair(1, 3));
    values3.push_back(make_pair(5, 8));
    values3.push_back(make_pair(9, 9));
    res = FunListStackQueueProblem::overlappingIntervals(values3);
    EXPECT_EQ(2, res.size());
    if (res.size()==1) {
        EXPECT_NE(res.end(),find_if(res.begin(),res.end(), [&](const pair<int,int>& e) { return e == make_pair(1,8); }));
        EXPECT_NE(res.end(),find_if(res.begin(),res.end(), [&](const pair<int,int>& e) { return e == make_pair(9,9); }));
    }
}


//=============================================================================
// Exercise 3: StackExt class
//=============================================================================
TEST(test_3, FindMin){
    cout << endl << "Testing 'findMin''" << endl;
    StackExt<int> s1;
    // Testing empty()
    EXPECT_EQ(true, s1.empty());
    // Testing push() e top()
    s1.push(6);
    s1.push(4);
    s1.push(7);
    s1.push(2);
    s1.push(5);
    EXPECT_EQ(5, s1.top());
    // Testing pop() e top()
    s1.pop();
    s1.pop();
    EXPECT_EQ(7, s1.top());

    // Testing findMin()
    EXPECT_EQ(4, s1.findMin());
    s1.push(3);
    EXPECT_EQ(3, s1.findMin());
    s1.push(3);
    s1.pop();
    EXPECT_EQ(3, s1.findMin());

    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    EXPECT_EQ(true, s1.empty());
}


//=============================================================================
// Exercise 4: Binary Numbers
//=============================================================================
TEST(test_4, BinaryNumbers) {
    cout << endl << "Testing 'binaryNumbers''" << endl;
    vector<string> res = FunListStackQueueProblem::binaryNumbers(2);
    vector<string> resok= {"1","10"};
    EXPECT_EQ(true, resok==res);

    res.clear(); res = FunListStackQueueProblem::binaryNumbers(5);
    resok= {"1","10","11","100","101"};
    EXPECT_EQ(true, resok==res);

    res.clear(); res = FunListStackQueueProblem::binaryNumbers(0);
    EXPECT_EQ(true, res.empty());
}


//=============================================================================
// Exercise 5: Calculate Span
//=============================================================================
TEST(test_5, StockSpan) {
    cout << endl << "Testing 'calculateSpan''" << endl;
    vector<int> res = FunListStackQueueProblem::calculateSpan({100, 80, 60, 70, 60, 75, 85});
    vector<int> resok = {1,1,1,2,1,4,6};
    EXPECT_EQ(true, resok==res);
    res = FunListStackQueueProblem::calculateSpan({10, 4, 5, 90, 120, 80});
    resok = {1,1,2,4,5,1};
    EXPECT_EQ(true, resok==res);
    res = FunListStackQueueProblem::calculateSpan({40, 35, 37, 36, 41});
    resok = {1,1,2,1,5};
    EXPECT_EQ(true, resok==res);
    res = FunListStackQueueProblem::calculateSpan({10, 4, 5, 90, 120, 80});
    resok = {1,1,2,4,5,1};
    EXPECT_EQ(true, resok==res);
    res = FunListStackQueueProblem::calculateSpan({});
    EXPECT_EQ(true,res.empty());
}


//=============================================================================
// Exercise 6: Pim Pam Pum
//=============================================================================
// Subexercise 6.1: Loose Game
//=============================================================================
TEST(test_6_1, loseGame){
    cout<<endl<<"Testing 'loseGame'"<<endl;
    Kid c1("Rui",6,'m');
    Kid c2("Ana",4,'f');
    Kid c3("Rita",6,'f');
    Kid c4("Joao",5,'m');
    Kid c5("Marta",4,'f');
    Kid c6("Vasco",5,'m');

//    Game game1;
//    game1.addKid(c1);
//    game1.addKid(c2);
//    game1.addKid(c3);
//    game1.addKid(c4);
//    game1.addKid(c5);
//    game1.addKid(c6);
    string s = "Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra es mesmo tu";
//    Kid cx = game1.loseGame(s);
//    EXPECT_EQ("Rui", cx.getName());

    Game game2;
    s = "Pim Pam Pum Pim";
    game2.addKid(c1);
    game2.addKid(c2);
    game2.addKid(c3);
    game2.addKid(c4);
    game2.addKid(c5);
    game2.addKid(c6);
    Kid cx = game2.loseGame(s);
    EXPECT_EQ("Marta", cx.getName());

//    Game game3;
//    s = "Pim Pam Pum";
//    game3.addKid(c1);
//    game3.addKid(c2);
//    game3.addKid(c3);
//    cx = game3.loseGame(s);
//    EXPECT_EQ("Ana", cx.getName());
}

//=============================================================================
// Subexercise 6.2: Rearrange
//=============================================================================
TEST(test_6_2, rearrange){
    cout<<endl<<"Testing 'rearrange'"<<endl;

    Kid c1("Rui",6,'m');
    Kid c2("Ana",4,'f');
    Kid c3("Maria",3,'f');
    Kid c4("Joao",5,'m');
    Kid c5("Vasco",7,'m');
    Kid c6("Luis",5,'m');

    Game game0;
    game0.addKid(c1);
    game0.addKid(c2);
    game0.addKid(c3);
    game0.addKid(c4);
    game0.addKid(c5);
    game0.addKid(c6);

    list<Kid> rem = game0.rearrange();
    EXPECT_EQ(0,rem.size());
    list<Kid>res = game0.getKids();
    EXPECT_EQ(6,res.size());
    if (res.size()==6) {
        vector<string> resok = {"Ana", "Rui", "Joao", "Maria", "Vasco", "Luis"};;
        for (auto kid1:resok) {
            EXPECT_EQ(kid1,res.front().getName());
            res.pop_front();
        }
    }

    Kid c7("Hugo",5,'m');
    Kid c8("Pedro",5,'m');
    Kid c9("Miguel",5,'m');
    Kid c10("Rita",5,'f');
    Game game1;
    game1.addKid(c1);
    game1.addKid(c2);
    game1.addKid(c3);
    game1.addKid(c4);
    game1.addKid(c5);
    game1.addKid(c6);
    game1.addKid(c7);
    game1.addKid(c8);
    game1.addKid(c9);
    game1.addKid(c10);

    rem = game1.rearrange();
    EXPECT_EQ(1,rem.size());
    if (!rem.empty())
        EXPECT_EQ("Miguel",rem.front().getName());
    res = game1.getKids();
    EXPECT_EQ(9,res.size());
    if (res.size()==9) {
        vector<string> resok = {"Ana", "Rui", "Joao", "Maria", "Vasco", "Luis", "Rita", "Hugo", "Pedro"};;
        for (auto kid1:resok) {
            EXPECT_EQ(kid1,res.front().getName());
            res.pop_front();
        }
    }
}

//=============================================================================
// Subexercise 6.3: Shuffle
//=============================================================================
TEST(test_6_3, shuffle){
    cout<<endl<<"Testing 'shuffle'"<<endl;
    list<Kid> kids;
    kids.push_back( Kid("Rui",6,'m') );
    kids.push_back( Kid("Ana",4,'f') );
    kids.push_back( Kid("Rita",3,'f') );
    kids.push_back( Kid("Joao",5,'m') );
    kids.push_back( Kid("Marta",7,'f') );
    kids.push_back( Kid("Vasco",5,'m') );
    kids.push_back( Kid("Ines",5,'f') );

    Game game1;
    game1.setKids(kids);

    list<Kid> kids2 = game1.shuffle();
    EXPECT_EQ(7, kids2.size());

    list<Kid>::iterator it;
    if(!kids2.empty()) {
        it= find(kids2.begin(), kids2.end(),Kid("Rui",6,'m'));
        EXPECT_EQ("Rui", it->getName());
    }

    if(!kids2.empty()) {
        it = find(kids2.begin(), kids2.end(), Kid("Ines", 5, 'm'));
        EXPECT_EQ("Ines", it->getName());
    }
}


//=============================================================================
// Exercise 7: Knight Jumps
//=============================================================================
TEST(test_7, KnightJumps) {
    cout << endl << "Testing 'knightJumps''" << endl;
    int res = FunListStackQueueProblem::knightJumps(4, 5, 1, 1, 6);
    EXPECT_EQ(3, res);
    res = FunListStackQueueProblem::knightJumps(1, 1, 15, 15, 16);
    EXPECT_EQ(10, res);
    res = FunListStackQueueProblem::knightJumps(2, 8, 8, 4, 8);
    EXPECT_EQ(4, res);
    res = FunListStackQueueProblem::knightJumps(4, 5, 4, 5, 6);
    EXPECT_EQ(0, res);
}


//=============================================================================
// BENCHMARK
//=============================================================================
static void BM_RemoveHigher(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        list<int> l;
        for (int i=0;i< state.range(0); i++)
            l.push_back (i%22+3);
        state.ResumeTiming();
        // This code gets timed
        FunListStackQueueProblem::removeHigher(l,12);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_OverlappingIntervals(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        list<pair<int,int>> l;
        for (int i=0;i< state.range(0); i++)
            l.push_back (make_pair(i%4,i%4+2));
        state.ResumeTiming();
        // This code gets timed
        FunListStackQueueProblem::overlappingIntervals(l);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_FindMin(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        StackExt<long> s1;
        for (long i=0;i< state.range(0); i++)
            s1.push (i%10+3);
        state.ResumeTiming();
        // This code gets timed
        s1.findMin();
    }
    state.SetComplexityN(state.range(0));
}

static void BM_BinaryNumbers(benchmark::State& state) {
    for (auto _ : state) {
        FunListStackQueueProblem::binaryNumbers(state.range(0));
    }
    state.SetComplexityN(state.range(0));
}

static void BM_StockSpan(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        vector<int> s;
        for (int i=0;i< state.range(0); i++) {
            s.push_back(i%10+3);
        }
        state.ResumeTiming();
        // This code gets timed
        FunListStackQueueProblem::calculateSpan(s);
    }
    state.SetComplexityN(state.range(0));
}

static void BM_LoseGame(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        Game game1;
        for (int i=0;i< state.range(0); i++)
            game1.addKid(Kid("aa",5,'f'));
        state.ResumeTiming();
        // This code gets timed
        game1.loseGame("pim pam pum cada bola mata um");
    }
    state.SetComplexityN(state.range(0));
}

static void BM_Rearrange(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        Game game1;
        for (int i=0;i< state.range(0); i+=3) {
            game1.addKid(Kid("aa", 5, 'f'));
            game1.addKid(Kid("aa", 5, 'm'));
            game1.addKid(Kid("aa", 5, 'f'));
        }
        state.ResumeTiming();
        // This code gets timed
        game1.rearrange();
    }
    state.SetComplexityN(state.range(0));
}

static void BM_Shuffle(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        Game game1;
        for (int i=0;i< state.range(0); i++)
            game1.addKid(Kid("aa"+i, 5, 'f'));
        state.ResumeTiming();
        // This code gets timed
        game1.shuffle();
    }
    state.SetComplexityN(state.range(0));
}

static void BM_KnightJumps(benchmark::State& state) {
    for (auto _ : state) {
        FunListStackQueueProblem::knightJumps(4, 5, 1, 1, state.range(0));
    }
    state.SetComplexityN(state.range(0));
}


//=============================================================================
// Register the functions as a benchmark
//=============================================================================

//NOTE: remove comments from respective BENCHMARKs to run complexity analysis

/*
BENCHMARK(BM_RemoveHigher)
        ->Unit(benchmark::kNanosecond)
        ->DenseRange(1<<12,1<<15,4096)
        ->Complexity();
*/

/*
BENCHMARK(BM_OverlappingIntervals)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_FindMin)
        ->Unit(benchmark::kNanosecond)
        ->Range(1<<2, 1<<6)
        ->Complexity();
*/

/*
BENCHMARK(BM_BinaryNumbers)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_StockSpan)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_LoseGame)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_Rearrange)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<10, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_Shuffle)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<12, 1<<18)
        ->Complexity();
*/

/*
BENCHMARK(BM_KnightJumps)
        ->Unit(benchmark::kNanosecond)
        ->Range(1<<2, 1<<10)
        ->Complexity();
*/


