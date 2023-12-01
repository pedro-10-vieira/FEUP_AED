#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Graph.h"
#include "Person.h"
#include "funWithGraphs.h"

using testing::Eq;


//=============================================================================
// Exercise 1: Graph
//=============================================================================
// Subexercise 1.1: Add Vertex
//=============================================================================
TEST(test_1_1, addVertex) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    EXPECT_EQ(false, g.addVertex(p2));
    EXPECT_EQ(4, g.getNumVertex());
}

//=============================================================================
// Subexercise 1.2: Add Edge
//=============================================================================
TEST(test_1_2, addEdge) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    EXPECT_EQ(true, g.addEdge(p1,p2,0));
    EXPECT_EQ(true, g.addEdge(p1,p3,0));
    EXPECT_EQ(true, g.addEdge(p1,p4,0));
    EXPECT_EQ(false, g.addEdge(p2,p5,0));
    Vertex<Person> *v = g.findVertex(p1);
    EXPECT_EQ(3, v->getAdj().size());
}

//=============================================================================
// Subexercise 1.3: Remove Edge
//=============================================================================
TEST(test_1_3, removeEdge) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    EXPECT_EQ(true, g.addEdge(p1,p2,0));
    EXPECT_EQ(true, g.addEdge(p1,p3,0));
    EXPECT_EQ(true, g.addEdge(p1,p4,0));
    Vertex<Person> *v = g.findVertex(p1);
    EXPECT_EQ(3, v->getAdj().size());
    EXPECT_EQ(true, g.addEdge(p2,p4,0));
    v = g.findVertex(p2);
    EXPECT_EQ(1, v->getAdj().size());
    EXPECT_EQ(true, g.removeEdge(p1,p3));
    v = g.findVertex(p1);
    EXPECT_EQ(2, v->getAdj().size());
    EXPECT_EQ(false, g.removeEdge(p1,p5));
    EXPECT_EQ(false, g.removeEdge(p2,p3));
    v = g.findVertex(p1);
    EXPECT_EQ(2, v->getAdj().size());
}

//=============================================================================
// Subexercise 1.4: Remove Vertex
//=============================================================================
TEST(test_1_4, removeVertex) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    EXPECT_EQ(true, g.removeVertex(p2));
    EXPECT_EQ(false, g.removeVertex(p2));
    EXPECT_EQ(3, g.getNumVertex());
}


//=============================================================================
// Exercise 2: Graph Degrees
//=============================================================================
// Subexercise 2.1: Out Degree
//=============================================================================
TEST(test_2_1, outDegree_Dir) {
    Graph<int> g;

    for (int i = 1; i <= 9; i++)
        g.addVertex(i);

    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 6, 0);
    g.addEdge(7, 5, 0);
    g.addEdge(8, 7, 0);
    g.addEdge(9, 6, 0);

    EXPECT_EQ(2, FunWithGraphs::outDegree(g, 1));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 2));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 3));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 4));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 5));
    EXPECT_EQ(0, FunWithGraphs::outDegree(g, 6));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 7));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 8));
    EXPECT_EQ(1, FunWithGraphs::outDegree(g, 9));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(g, -42));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(g, 0));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(g, 10));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(g, 42));
}

//=============================================================================
// Subexercise 2.2: In Degree
//=============================================================================
TEST(test_2_2, inDegree) {
    Graph<int> g;

    for(int i = 1; i <= 9; i++)
        g.addVertex(i);

    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(2,4,0);
    g.addEdge(3,4,0);
    g.addEdge(4,5,0);
    g.addEdge(5,6,0);
    g.addEdge(7,5,0);
    g.addEdge(8,7,0);
    g.addEdge(9,6,0);

    EXPECT_EQ(0, FunWithGraphs::inDegree(g, 1));
    EXPECT_EQ(1, FunWithGraphs::inDegree(g, 2));
    EXPECT_EQ(1, FunWithGraphs::inDegree(g, 3));
    EXPECT_EQ(2, FunWithGraphs::inDegree(g, 4));
    EXPECT_EQ(2, FunWithGraphs::inDegree(g, 5));
    EXPECT_EQ(2, FunWithGraphs::inDegree(g, 6));
    EXPECT_EQ(1, FunWithGraphs::inDegree(g, 7));
    EXPECT_EQ(0, FunWithGraphs::inDegree(g, 8));
    EXPECT_EQ(0, FunWithGraphs::inDegree(g, 9));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(g, -42));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(g, 0));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(g, 10));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(g, 42));
}

//=============================================================================
// Subexercise 2.3: Weighted Out Degree
//=============================================================================
TEST(test_2_3, weightedOutDegree) {
    Graph<int> g;

    for (int i = 1; i <= 9; i++)
        g.addVertex(i);

    g.addEdge(1,2,5);
    g.addEdge(1,3,4);
    g.addEdge(2,4,8);
    g.addEdge(3,4,7);
    g.addEdge(4,5,3);
    g.addEdge(5,6,5);
    g.addEdge(7,5,9);
    g.addEdge(9,6,1);
    g.addEdge(8,7,2);
    g.addEdge(9,8,42);

    EXPECT_EQ(9, FunWithGraphs::weightedOutDegree(g, 1));
    EXPECT_EQ(8, FunWithGraphs::weightedOutDegree(g, 2));
    EXPECT_EQ(7, FunWithGraphs::weightedOutDegree(g, 3));
    EXPECT_EQ(3, FunWithGraphs::weightedOutDegree(g, 4));
    EXPECT_EQ(5, FunWithGraphs::weightedOutDegree(g, 5));
    EXPECT_EQ(0, FunWithGraphs::weightedOutDegree(g, 6));
    EXPECT_EQ(9, FunWithGraphs::weightedOutDegree(g, 7));
    EXPECT_EQ(2, FunWithGraphs::weightedOutDegree(g, 8));
    EXPECT_EQ(-1, FunWithGraphs::weightedOutDegree(g, 0));
    EXPECT_EQ(-1, FunWithGraphs::weightedOutDegree(g, 10));
}

//=============================================================================
// 2.4 Vertex degree in undirected graphs
//=============================================================================
TEST(test_2_4_1, undir_from_outDegree) {
    Graph<int> gUndir;

    for(int i = 1; i <= 9; i++)
        gUndir.addVertex(i);

    gUndir.addEdge(1,2,0);
    gUndir.addEdge(2,1,0);
    gUndir.addEdge(1,3,0);
    gUndir.addEdge(3,1,0);
    gUndir.addEdge(2,4,0);
    gUndir.addEdge(4,2,0);
    gUndir.addEdge(3,4,0);
    gUndir.addEdge(4,3,0);
    gUndir.addEdge(4,5,0);
    gUndir.addEdge(5,4,0);
    gUndir.addEdge(5,6,0);
    gUndir.addEdge(6,5,0);
    gUndir.addEdge(5,7,0);
    gUndir.addEdge(7,5,0);
    gUndir.addEdge(6,9,0);
    gUndir.addEdge(9,6,0);
    gUndir.addEdge(7,8,0);
    gUndir.addEdge(8,7,0);

    EXPECT_EQ(2, FunWithGraphs::outDegree(gUndir, 1));
    EXPECT_EQ(2, FunWithGraphs::outDegree(gUndir, 2));
    EXPECT_EQ(2, FunWithGraphs::outDegree(gUndir, 3));
    EXPECT_EQ(3, FunWithGraphs::outDegree(gUndir, 4));
    EXPECT_EQ(3, FunWithGraphs::outDegree(gUndir, 5));
    EXPECT_EQ(2, FunWithGraphs::outDegree(gUndir, 6));
    EXPECT_EQ(2, FunWithGraphs::outDegree(gUndir, 7));
    EXPECT_EQ(1, FunWithGraphs::outDegree(gUndir, 8));
    EXPECT_EQ(1, FunWithGraphs::outDegree(gUndir, 9));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(gUndir, -42));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(gUndir, 0));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(gUndir, 10));
    EXPECT_EQ(-1, FunWithGraphs::outDegree(gUndir, 42));
}


TEST(test_2_4_2, undir_from_inDegree) {
    Graph<int> gUndir;

    for(int i = 1; i <= 9; i++)
        gUndir.addVertex(i);

    gUndir.addEdge(1,2,0);
    gUndir.addEdge(2,1,0);
    gUndir.addEdge(1,3,0);
    gUndir.addEdge(3,1,0);
    gUndir.addEdge(2,4,0);
    gUndir.addEdge(4,2,0);
    gUndir.addEdge(3,4,0);
    gUndir.addEdge(4,3,0);
    gUndir.addEdge(4,5,0);
    gUndir.addEdge(5,4,0);
    gUndir.addEdge(5,6,0);
    gUndir.addEdge(6,5,0);
    gUndir.addEdge(5,7,0);
    gUndir.addEdge(7,5,0);
    gUndir.addEdge(6,9,0);
    gUndir.addEdge(9,6,0);
    gUndir.addEdge(7,8,0);
    gUndir.addEdge(8,7,0);

    EXPECT_EQ(2, FunWithGraphs::inDegree(gUndir, 1));
    EXPECT_EQ(2, FunWithGraphs::inDegree(gUndir, 2));
    EXPECT_EQ(2, FunWithGraphs::inDegree(gUndir, 3));
    EXPECT_EQ(3, FunWithGraphs::inDegree(gUndir, 4));
    EXPECT_EQ(3, FunWithGraphs::inDegree(gUndir, 5));
    EXPECT_EQ(2, FunWithGraphs::inDegree(gUndir, 6));
    EXPECT_EQ(2, FunWithGraphs::inDegree(gUndir, 7));
    EXPECT_EQ(1, FunWithGraphs::inDegree(gUndir, 8));
    EXPECT_EQ(1, FunWithGraphs::inDegree(gUndir, 9));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(gUndir, -42));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(gUndir, 0));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(gUndir, 10));
    EXPECT_EQ(-1, FunWithGraphs::inDegree(gUndir, 42));
}
