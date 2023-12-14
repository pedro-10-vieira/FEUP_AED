#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Graph.h"
#include "funWithGraphs.h"

using testing::Eq;


//=============================================================================
// Exercise 1: Topological Sorting
//=============================================================================
TEST(test_1, topsort_g1) {
    Graph<int> g;
    for (int i = 1; i <= 4; i++)
        g.addVertex(i);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);

    std::vector<int> topOrder = g.topsort();
    EXPECT_EQ(4, topOrder.size());
    std::stringstream ss;
    for (unsigned int i = 0; i < topOrder.size(); i++)
        ss << topOrder[i] << " ";
    EXPECT_EQ("1 2 3 4 ", ss.str());
}

TEST(test_1, topsort_g2) {
    Graph<int> g2;
    for (int i = 1; i <= 7; i++)
        g2.addVertex(i);
    g2.addEdge(1, 2, 0);
    g2.addEdge(1, 4, 0);
    g2.addEdge(1, 3, 0);
    g2.addEdge(2, 5, 0);
    g2.addEdge(2, 4, 0);
    g2.addEdge(3, 6, 0);
    g2.addEdge(4, 3, 0);
    g2.addEdge(4, 6, 0);
    g2.addEdge(4, 7, 0);
    g2.addEdge(5, 4, 0);
    g2.addEdge(5, 7, 0);
    g2.addEdge(7, 6, 0);

    std::vector<int> topOrder = g2.topsort();
    EXPECT_EQ(7, topOrder.size());
    std::stringstream ss;
    for (unsigned int i = 0; i < topOrder.size(); i++)
        ss << topOrder[i] << " ";
    EXPECT_EQ("1 2 5 4 3 7 6 ", ss.str());

    // to test including a cycle in the graph
    g2.addEdge(3, 1, 0);

    topOrder = g2.topsort();
    ss.str("");
    EXPECT_EQ(0, topOrder.size());
    for (unsigned int i = 0; i < topOrder.size(); i++)
        ss << topOrder[i] << " ";
    EXPECT_EQ("", ss.str());
}

TEST(test_1, topsort_g3_ExampleGraph) {
    Graph<int> g3;
    for (int i = 1; i <= 9; i++)
        g3.addVertex(i);
    g3.addEdge(1, 2, 0);
    g3.addEdge(1, 3, 0);
    g3.addEdge(2, 4, 0);
    g3.addEdge(3, 4, 0);
    g3.addEdge(4, 5, 0);
    g3.addEdge(5, 6, 0);
    g3.addEdge(9, 6, 0);
    g3.addEdge(7, 5, 0);
    g3.addEdge(8, 7, 0);

    std::vector<int> topOrder = g3.topsort();
    EXPECT_EQ(9, topOrder.size());
    for (int v = 1; v <= 9; v++) EXPECT_NE(topOrder.end(), find(topOrder.begin(), topOrder.end(), v));
    vector<pair<int, int>> edges = {{1, 2},
                                    {1, 3},
                                    {2, 4},
                                    {3, 4},
                                    {4, 5},
                                    {5, 6},
                                    {9, 6},
                                    {7, 5},
                                    {8, 7}};
    for (auto e: edges) {
        auto u = find(topOrder.begin(), topOrder.end(), e.first);
        auto v = find(topOrder.begin(), topOrder.end(), e.second);
        EXPECT_LT(distance(topOrder.begin(), u), distance(topOrder.begin(), v));
    }
}

TEST(test_1, topsort_g4) {
    Graph<int> g4;
    for (int i = 1; i <= 8; i++)
        g4.addVertex(i);
    g4.addEdge(1, 3, 3);
    g4.addEdge(2, 1, 2);
    g4.addEdge(4, 2, 1);
    g4.addEdge(5, 4, 1);
    g4.addEdge(5, 6, 2);
    g4.addEdge(6, 8, 1);
    g4.addEdge(6, 7, 2);
    g4.addEdge(8, 7, 3);

    std::vector<int> topOrder = g4.topsort();
    EXPECT_EQ(8, topOrder.size());
    for (int v = 1; v <= 8; v++) EXPECT_NE(topOrder.end(), find(topOrder.begin(), topOrder.end(), v));
    vector<pair<int, int>> edges10 = {{2, 1},
                                      {1, 3},
                                      {4, 2},
                                      {5, 4},
                                      {5, 6},
                                      {6, 7},
                                      {6, 8},
                                      {8, 7}};
    for (auto e: edges10) {
        auto u = find(topOrder.begin(), topOrder.end(), e.first);
        auto v = find(topOrder.begin(), topOrder.end(), e.second);
        EXPECT_LT(distance(topOrder.begin(), u), distance(topOrder.begin(), v)); // pos(u) < pos(v)
    }
}


//=============================================================================
// Exercise 2.1: Connected Components
//=============================================================================
Graph<int> g1() {
    Graph<int> g;
    for (int i = 1; i <= 9; i++)
        g.addVertex(i);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 1, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 2, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(6, 5, 0);
    g.addEdge(5, 7, 0);
    g.addEdge(7, 5, 0);
    g.addEdge(6, 9, 0);
    g.addEdge(9, 6, 0);
    g.addEdge(7, 8, 0);
    g.addEdge(8, 7, 0);

    return g;
}
Graph<int> g2() {
    Graph<int> g;
    for (int i = 1; i <= 9; i++)
        g.addVertex(i);
    g.addEdge(1,2,0);
    g.addEdge(2,1,0);
    g.addEdge(1,3,0);
    g.addEdge(3,1,0);
    g.addEdge(2,3,0);
    g.addEdge(3,2,0);
    g.addEdge(4,5,0);
    g.addEdge(5,4,0);
    g.addEdge(6,9,0);
    g.addEdge(9,6,0);
    g.addEdge(6,7,0);
    g.addEdge(7,6,0);
    g.addEdge(8,7,0);
    g.addEdge(7,8,0);
    g.addEdge(8,9,0);
    g.addEdge(9,8,0);

    return g;
}

Graph<int> g3() {
    Graph<int> g;
    for (int i = 1; i <= 12; i++)
        g.addVertex(i);
    g.addEdge(8,1,0);
    g.addEdge(1,8,0);
    g.addEdge(8,2,0);
    g.addEdge(2,8,0);
    g.addEdge(8,3,0);
    g.addEdge(3,8,0);
    g.addEdge(8,7,0);
    g.addEdge(7,8,0);
    g.addEdge(8,9,0);
    g.addEdge(9,8,0);
    g.addEdge(1,2,0);
    g.addEdge(2,1,0);
    g.addEdge(2,3,0);
    g.addEdge(3,2,0);
    g.addEdge(3,4,0);
    g.addEdge(4,3,0);
    g.addEdge(5,6,0);
    g.addEdge(6,5,0);
    g.addEdge(5,11,0);
    g.addEdge(11,5,0);
    g.addEdge(5,11,0);
    g.addEdge(11,5,0);
    g.addEdge(5,5,0);
    g.addEdge(12,12,0);
    g.addEdge(6,11,0);
    g.addEdge(11,6,0);
    g.addEdge(6,12,0);
    g.addEdge(12,6,0);
    g.addEdge(12,11,0);
    g.addEdge(11,12,0);
    g.addEdge(11,10,0);
    g.addEdge(10,11,0);

    return g;
}

Graph<int> g4(){
    Graph<int> g;
    for (int i = 1; i <= 9; i++)
        g.addVertex(i);
    g.addEdge(1,2, 5);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 8);
    g.addEdge(3,4, 7);
    g.addEdge(4,5, 3);
    g.addEdge(5,6, 5);
    g.addEdge(5,7, 9);
    g.addEdge(6,9, 1);
    g.addEdge(7,8, 2);
    g.addEdge(8,9, 42);

    return g;
}

Graph<int> g5(){
    Graph<int> g;
    for (int i = 1; i <= 4; i++)
        g.addVertex(i);

    g.addEdge(1,2, 3);
    g.addEdge(1,3, 4);
    g.addEdge(2,4, 3);
    g.addEdge(3,4, 4);

    return g;
}

TEST(test_2_1, connectedComponents_g1_Graph1) {
    Graph<int> g = g1();
    EXPECT_EQ(1, funWithGraphs::connectedComponents(&g));
}


TEST(test_2_1, connectedComponents_g2_Graph2) {
    Graph<int> g = g2();
    EXPECT_EQ(3, funWithGraphs::connectedComponents(&g));
}

TEST(test_2_1, connectedComponents_g3) {
    Graph<int> g = g3();
    EXPECT_EQ(2, funWithGraphs::connectedComponents(&g));
}

TEST(test_2_1, connectedComponents_g4) {
    Graph<int> g = g4();

    EXPECT_EQ(1, funWithGraphs::connectedComponents(&g));
}

TEST(test_2_1, connectedComponents_g5) {
    Graph<int> g = g5();

    EXPECT_EQ(1, funWithGraphs::connectedComponents(&g));
}

//=============================================================================
// Exercise 2.2: Giant Component
//=============================================================================
TEST(test_2_2, giantComponent_g1_Graph1) {
    Graph<int> g = g1();

    EXPECT_EQ(9, funWithGraphs::giantComponent(&g));
}

TEST(test_2_2, giantComponent_g2_Graph2) {
    Graph<int> g = g2();

    EXPECT_EQ(4, funWithGraphs::giantComponent(&g));
}

TEST(test_2_2, giantComponent_g3) {
    Graph<int> g = g3();

    EXPECT_EQ(7, funWithGraphs::giantComponent(&g));
}

TEST(test_2_2, giantComponent_g4) {
    Graph<int> g = g4();

    EXPECT_EQ(9, funWithGraphs::giantComponent(&g));
}

TEST(test_2_2, giantComponent_g5) {
    Graph<int> g = g5();

    EXPECT_EQ(4, funWithGraphs::giantComponent(&g));
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
TEST(test_2_3, scc_g1_Graph1) {
    Graph<int> g;
    for (int i = 1; i <= 8; i++)
        g.addVertex(i);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(5, 1, 0);
    g.addEdge(2, 6, 0);
    g.addEdge(7, 3, 0);
    g.addEdge(3, 8, 0);
    g.addEdge(8, 4, 0);
    g.addEdge(6, 5, 0);
    g.addEdge(8, 7, 0);

    list<list<int>> lscc = funWithGraphs::scc(&g);
    EXPECT_EQ(2, lscc.size());
    for (auto &l: lscc) l.sort();
    lscc.sort();
    list<list<int>> res = {{1, 2, 5, 6},
                            {3, 4, 7, 8}};
    EXPECT_EQ(lscc, res);
}

TEST(test_2_3, scc_g2_Graph2) {
    Graph<int> g;
    for (int i = 1; i <= 8; i++)
        g.addVertex(i);
    g.addEdge(1, 5, 0);
    g.addEdge(1, 6, 0);
    g.addEdge(2, 1, 0);
    g.addEdge(3, 2, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 8, 0);
    g.addEdge(6, 3, 0);
    g.addEdge(7, 3, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 8, 0);
    g.addEdge(8, 4, 0);

    list<list<int>> lscc = funWithGraphs::scc(&g);
    EXPECT_EQ(4, lscc.size());
    for (auto & l : lscc) l.sort();
    lscc.sort();
    list<list<int>> res = {{1,2,3,6},{4,8},{5},{7}};
    EXPECT_EQ(lscc, res);

}

TEST(test_2_3, scc_g3_Graph3) {
    Graph<int> g;
    for (int i = 1; i <= 8; i++)
        g.addVertex(i);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(4, 8, 0);
    g.addEdge(5, 1, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(6, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(8, 7, 0);
    g.addEdge(8, 4, 0);

    list<list<int>> lscc = funWithGraphs::scc(&g);
    EXPECT_EQ(3, lscc.size());
    for (auto &l: lscc) l.sort();
    lscc.sort();
    list<list<int>> res = {{1, 2, 5},
                            {3, 4, 8},
                            {6, 7}};
    EXPECT_EQ(lscc, res);
}

TEST(test_2_3, scc_g4_Graph4) {
    Graph<int> g;
    for (int i = 1; i <= 7; i++)
        g.addVertex(i);
    g.addEdge(1, 2, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(5, 1, 0);
    g.addEdge(5, 2, 0);
    g.addEdge(6, 2, 0);
    g.addEdge(6, 3, 0);
    g.addEdge(7, 4, 0);

    list<list<int>> lscc = funWithGraphs::scc(&g);
    EXPECT_EQ(7, lscc.size());
    for (auto & l : lscc) l.sort();
    lscc.sort();
    list<list<int>> res = {{1},{2},{3},{4},{5},{6},{7}};
    EXPECT_EQ(lscc, res);
}

//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
TEST(test_2_4, articulationPoints_g1_Graph1) {
    Graph<int> g1;
    for (int i = 1; i <= 10; i++)
        g1.addVertex(i);
    g1.addEdge(1, 2, 0);
    g1.addEdge(2, 1, 0);
    g1.addEdge(1, 4, 0);
    g1.addEdge(4, 1, 0);
    g1.addEdge(2, 3, 0);
    g1.addEdge(3, 2, 0);
    g1.addEdge(3, 4, 0);
    g1.addEdge(4, 3, 0);
    g1.addEdge(3, 5, 0);
    g1.addEdge(5, 3, 0);
    g1.addEdge(6, 5, 0);
    g1.addEdge(5, 6, 0);
    g1.addEdge(5, 7, 0);
    g1.addEdge(7, 5, 0);
    g1.addEdge(5, 9, 0);
    g1.addEdge(9, 5, 0);
    g1.addEdge(7, 8, 0);
    g1.addEdge(8, 7, 0);
    g1.addEdge(9, 8, 0);
    g1.addEdge(8, 9, 0);
    g1.addEdge(10, 8, 0);
    g1.addEdge(8, 10, 0);

    unordered_set<int> us1 = funWithGraphs::articulationPoints(&g1);
    unordered_set<int> res1 = {3, 5, 8};
    EXPECT_EQ(us1, res1);
}

TEST(test_2_4, articulationPoints_g2_Graph2) {
    Graph<int> g2;
    for (int i = 1; i <= 4; i++)
        g2.addVertex(i);
    g2.addEdge(1, 2, 0);
    g2.addEdge(2, 1, 0);
    g2.addEdge(2, 3, 0);
    g2.addEdge(3, 2, 0);
    g2.addEdge(3, 4, 0);
    g2.addEdge(4, 3, 0);
    g2.addEdge(1, 4, 0);
    g2.addEdge(4, 1, 0);

    unordered_set<int> us2 = funWithGraphs::articulationPoints(&g2);
    unordered_set<int> res2 = {};
    EXPECT_EQ(us2, res2);
}

TEST(test_2_4, articulationPoints_g3_Graph3) {
    Graph<int> g3;
    for (int i = 1; i <= 5; i++)
        g3.addVertex(i);
    g3.addEdge(1, 2, 0);
    g3.addEdge(2, 1, 0);
    g3.addEdge(1, 5, 0);
    g3.addEdge(5, 1, 0);
    g3.addEdge(1, 3, 0);
    g3.addEdge(3, 1, 0);
    g3.addEdge(1, 4, 0);
    g3.addEdge(4, 1, 0);

    unordered_set<int> us3 = funWithGraphs::articulationPoints(&g3);
    unordered_set<int> res3 = {1};
    EXPECT_EQ(us3, res3);
}

TEST(test_2_4, articulationPoints_g4_Graph1) {
    Graph<int> g4;
    for (int i = 1; i <= 8; i++)
        g4.addVertex(i);
    g4.addEdge(1, 2, 0);
    g4.addEdge(2, 1, 0);
    g4.addEdge(1, 5, 0);
    g4.addEdge(5, 1, 0);
    g4.addEdge(2, 5, 0);
    g4.addEdge(5, 2, 0);
    g4.addEdge(5, 6, 0);
    g4.addEdge(6, 5, 0);
    g4.addEdge(2, 3, 0);
    g4.addEdge(3, 2, 0);
    g4.addEdge(3, 4, 0);
    g4.addEdge(4, 3, 0);
    g4.addEdge(3, 8, 0);
    g4.addEdge(8, 3, 0);
    g4.addEdge(7, 8, 0);
    g4.addEdge(8, 7, 0);
    g4.addEdge(4, 8, 0);
    g4.addEdge(8, 4, 0);

    unordered_set<int> us4 = funWithGraphs::articulationPoints(&g4);
    unordered_set<int> res4 = {2, 3, 5, 8};
    EXPECT_EQ(us4, res4);
}
