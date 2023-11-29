#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark.h>
#include "box.h"
#include "packagingMachine.h"
#include "funPQProblem.h"

using testing::Eq;


//=============================================================================
// Exercise 1: Packaging
//=============================================================================
// Subexercise 1.1: Load Objects
//=============================================================================
TEST(test_1_1, loadObjects) {
    cout<<endl<<"Testing 'loadObjects'"<<endl;
    vector<Object> objects;
    objects.push_back(Object(1, 2)); objects.push_back(Object(2, 11));
    objects.push_back(Object(3, 17)); objects.push_back(Object(4, 3));
    objects.push_back(Object(5, 9)); objects.push_back(Object(6, 4));
    objects.push_back(Object(7, 2)); objects.push_back(Object(8, 12));
    objects.push_back(Object(9, 7)); objects.push_back(Object(10, 1));

    PackagingMachine machine;
    int objsLoaded = machine.loadObjects(objects);
    int objsNotLoaded  = objects.size();
    EXPECT_EQ(7, objsLoaded);
    EXPECT_EQ(3, objsNotLoaded);
    HeapObj objectsH= machine.getObjects();
    bool isEmp = objectsH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(5,objectsH.top().getID());
}

//=============================================================================
// Subexercise 1.2: Search Box
//=============================================================================
TEST(test_1_2, searchBox) {
    cout<<endl<<"Testing 'searchBox'"<<endl;
    vector<Object> objects;
    objects.push_back(Object(1, 2)); objects.push_back(Object(2, 5));
    objects.push_back(Object(3, 8)); objects.push_back(Object(4, 1));
    objects.push_back(Object(5, 4)); objects.push_back(Object(6, 6));
    objects.push_back(Object(7, 1)); objects.push_back(Object(8, 4));

    Box b1; //7
    b1.addObject( objects[0] );
    b1.addObject( objects[1] );
    Box b2; //8
    b2.addObject( objects[2] );

    PackagingMachine machine;
    machine.addBox( b1 );
    machine.addBox( b2 );

    cout << "Free in Box : " << b1.getFree() << endl; //3
    cout << "Free in Box : " << b2.getFree() << endl; //2

    EXPECT_EQ(2, machine.numberOfBoxes()); // 8 7
    HeapBox boxesH= machine.getBoxes();
    bool isEmp = boxesH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(2,boxesH.top().getFree());

    Box bx = machine.searchBox( objects[3] );
    bx.addObject( objects[3] );
    machine.addBox( bx );
    //cout << "Carga livre em C" << bx.getID() << ": " << bx.getFree() << endl;
    EXPECT_EQ(2, machine.numberOfBoxes()); // 9 7
    boxesH= machine.getBoxes();
    isEmp = boxesH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(1,boxesH.top().getFree());

    bx = machine.searchBox( objects[4] );
    bx.addObject( objects[4] );
    machine.addBox( bx );
    cout << "Free in Box : " << bx.getFree() << endl;
    EXPECT_EQ(3, machine.numberOfBoxes()); // 9 7 4
    boxesH= machine.getBoxes();
    isEmp = boxesH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(1,boxesH.top().getFree());

    bx = machine.searchBox( objects[5] );
    bx.addObject( objects[5] );
    machine.addBox( bx );
    cout << "Free in Box : " << bx.getFree() << endl;
    EXPECT_EQ(3, machine.numberOfBoxes()); // 10 9 7
    boxesH= machine.getBoxes();
    isEmp = boxesH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(0,boxesH.top().getFree());

    bx = machine.searchBox( objects[6] );
    bx.addObject( objects[6] );
    machine.addBox( bx );
    cout << "Free in Box : " << bx.getFree() << endl;
    EXPECT_EQ(3, machine.numberOfBoxes()); // 10 10 7
    boxesH = machine.getBoxes();
    EXPECT_EQ(3,boxesH.size());
    if (boxesH.size()==3) {
        boxesH.pop();
        EXPECT_EQ(0, boxesH.top().getFree());
    }

    bx = machine.searchBox( objects[7] );
    bx.addObject( objects[7] );
    machine.addBox( bx );
    cout << "Free in Box : " << bx.getFree() << endl;
    EXPECT_EQ(4, machine.numberOfBoxes()); // 10 10 7 6
    boxesH = machine.getBoxes();
    EXPECT_EQ(4,boxesH.size());
    if (boxesH.size()==4) {
        boxesH.pop();
        boxesH.pop();
        EXPECT_EQ(3, boxesH.top().getFree());
    }
}

//=============================================================================
// Subexercise 1.3: Pack Objects
//=============================================================================
TEST(test_1_3, packObjects) {
    cout<<endl<<"Testing 'packObjects'"<<endl;
    vector<Object> objects;
    objects.push_back(Object(1, 2)); objects.push_back(Object(2, 11));
    objects.push_back(Object(3, 17)); objects.push_back(Object(4, 3));
    objects.push_back(Object(5, 9)); objects.push_back(Object(6, 4));
    objects.push_back(Object(7, 2)); objects.push_back(Object(8, 12));
    objects.push_back(Object(9, 7)); objects.push_back(Object(10, 10));
    objects.push_back(Object(11, 10)); objects.push_back(Object(12, 1));

    PackagingMachine machine;

    EXPECT_EQ(9, machine.loadObjects(objects));
    EXPECT_EQ(3, objects.size());
    EXPECT_EQ(5, machine.packObjects());

    HeapBox boxes = machine.getBoxes();
    EXPECT_EQ(5, boxes.size());
    if (boxes.size()==5) {
        EXPECT_EQ(0, boxes.top().getFree());
        boxes.pop();
        EXPECT_EQ(0, boxes.top().getFree());
        boxes.pop();
        EXPECT_EQ(0, boxes.top().getFree());
        boxes.pop();
        EXPECT_EQ(0, boxes.top().getFree());
        boxes.pop();
        EXPECT_EQ(2, boxes.top().getFree());
    }
}

//=============================================================================
// Subexercise 1.4: Box with More Objects
//=============================================================================
TEST(test_1_4, boxMoreObjects) {
    cout<<endl<<"Testing 'box With More Objects'"<<endl;
    vector<Object> objects;
    objects.push_back(Object(1, 2));
    objects.push_back(Object(4, 3));
    objects.push_back(Object(5, 9));
    objects.push_back(Object(6, 4));
    objects.push_back(Object(7, 2));
    objects.push_back(Object(9, 7));
    objects.push_back(Object(10, 10));
    objects.push_back(Object(11, 10));
    objects.push_back(Object(12, 1));

    PackagingMachine machine;
    stack<Object> objs =machine.boxWithMoreObjects();
    EXPECT_EQ(0,objs.size());

    EXPECT_EQ(9, machine.loadObjects(objects));
    EXPECT_EQ(0, objects.size());
    EXPECT_EQ(5, machine.packObjects());
    objs = machine.boxWithMoreObjects();
    EXPECT_EQ(3, objs.size());
}


//=============================================================================
// Exercise 2: Minimum Cost
//=============================================================================
TEST(test_2, minCost) {
    cout<<endl<<"Testing 'min Cost connecting ropes'"<<endl;
    int res = FunPQProblem::minCost({4,3,2,6});
    EXPECT_EQ(29, res);
    res = FunPQProblem::minCost({4, 2, 7, 6, 9});
    EXPECT_EQ(62, res);
}


//=============================================================================
// BENCHMARK
//=============================================================================
static void BM_MinCost(benchmark::State& state) {
    vector<int> v(state.range(0));
    for (auto _ : state) {
        state.PauseTiming();
        // runtime of this will be ignored
        for (long i=0;i< state.range(0); i++)
            v.at(i) = i%10+3;
        state.ResumeTiming();
        // This code gets timed
        FunPQProblem::minCost(v);
    }
    state.SetComplexityN(state.range(0));
}


//=============================================================================
// Register the functions as a benchmark
//=============================================================================

//NOTE: remove comments from respective BENCHMARKs to run complexity analysis

/*
BENCHMARK(BM_MinCost)
        ->Unit(benchmark::kNanosecond)
        ->RangeMultiplier(2)->Range(1<<5, 1<<12)
        ->Complexity();
*/
