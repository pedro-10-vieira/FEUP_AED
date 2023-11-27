#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include "Graph.h"
#include "Person.h"
#include "funWithDFS.h"
#include "funWithBFS.h"

using testing::Eq;

//=============================================================================
// Exercise 1.1: Depth First Search
//=============================================================================
// Subexercise 1.1.1: Depth First Search (Graph Traversal)
//=============================================================================
TEST(test_1_1_1, dfs) {
    Graph<int> g_int;
    for (int i = 0; i < 4; i++)
        g_int.addVertex(i);

    g_int.addEdge(0, 1, 0);
    g_int.addEdge(0, 2, 0);
    g_int.addEdge(1, 2, 0);
    g_int.addEdge(2, 0, 0);
    g_int.addEdge(2, 3, 0);
    g_int.addEdge(3, 3, 0);

    std::vector<int> v_int = g_int.dfs();
    vector<int> sequence = {0, 1, 2, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence[i], v_int[i]);

    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    Person p6("Rui",21);
    Person p7("Vasco",28);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    g.addVertex(p5); g.addVertex(p6); g.addVertex(p7);
    g.addEdge(p1,p2,0);
    g.addEdge(p1,p3,0);
    g.addEdge(p1,p4,0);
    g.addEdge(p2,p5,0);
    g.addEdge(p5,p6,0);
    g.addEdge(p5,p1,0);
    g.addEdge(p3,p6,0);
    g.addEdge(p3,p7,0);
    g.addEdge(p6,p2,0);

    std::vector<Person> v1 = g.dfs();
    std::string names1[] = {"Ana", "Carlos", "Maria", "Rui", "Filipe", "Vasco", "Ines"};
    EXPECT_EQ(v1.size(), 7);
    for (unsigned i = 0; i < v1.size(); i++)
        EXPECT_EQ(names1[i], v1[i].getName());

    p5 = Person("Maria", 24);
    p6 = Person("Rui",21);
    EXPECT_EQ(true, g.removeEdge(p5,p6));
    std::vector<Person> v2=g.dfs();
    std::string names2[] = {"Ana", "Carlos", "Maria", "Filipe", "Rui", "Vasco", "Ines"};
    EXPECT_EQ(v2.size(), 7);
    for (unsigned i = 0; i < v2.size(); i++)
        EXPECT_EQ(names2[i], v2[i].getName());

    p2 = Person("Carlos",33);
    EXPECT_EQ(true, g.removeVertex(p2));
    std::vector<Person> v3=g.dfs();
    std::string names3[] = {"Ana", "Filipe", "Rui", "Vasco", "Ines", "Maria"};
    EXPECT_EQ(v3.size(), 6);
    for (unsigned i = 0; i < v3.size(); i++)
        EXPECT_EQ(names3[i], v3[i].getName());
}

//=============================================================================
// Subexercise 1.1.2: Depth First Search (From a source node)
//=============================================================================
TEST(test_1_1_2, dfs) {
    Graph<int> g_int;
    for (int i = 0; i < 4; i++)
        g_int.addVertex(i);

    g_int.addEdge(0, 1, 0);
    g_int.addEdge(0, 2, 0);
    g_int.addEdge(1, 2, 0);
    g_int.addEdge(2, 0, 0);
    g_int.addEdge(2, 3, 0);
    g_int.addEdge(3, 3, 0);

    std::vector<int> v_int = g_int.dfs();
    vector<int> sequence = {0, 1, 2, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence[i], v_int[i]);

    v_int = g_int.dfs(0);
    vector<int> sequence1 = {0, 1, 2, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence1[i], v_int[i]);
    v_int = g_int.dfs(1);
    vector<int> sequence2 = {1, 2, 0, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence2[i], v_int[i]);
    v_int = g_int.dfs(2);
    vector<int> sequence3 = {2, 0, 1, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence3[i], v_int[i]);
    v_int = g_int.dfs(3);
    vector<int> sequence4 = {3};
    EXPECT_EQ(v_int.size(), 1);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence4[i], v_int[i]);
}


//=============================================================================
// Exercise 1.2: Breadth First Search
//=============================================================================
TEST(test_1_2, bfs) {

    Graph<int> g_int;
    for (int i = 0; i <= 3; i++)
        g_int.addVertex(i);

    g_int.addEdge(0, 1, 0);
    g_int.addEdge(0, 2, 0);
    g_int.addEdge(1, 2, 0);
    g_int.addEdge(2, 0, 0);
    g_int.addEdge(2, 3, 0);
    g_int.addEdge(3, 3, 0);

    std::vector<int> v_int = g_int.bfs(0);
    vector<int> sequence = {0, 1, 2, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence[i], v_int[i]);
    v_int = g_int.bfs(1);
    vector<int> sequence2 = {1, 2, 0, 3};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence2[i], v_int[i]);
    v_int = g_int.bfs(2);
    vector<int> sequence3 = {2, 0, 3, 1};
    EXPECT_EQ(v_int.size(), 4);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence3[i], v_int[i]);
    v_int = g_int.bfs(3);
    vector<int> sequence4 = {3};
    EXPECT_EQ(v_int.size(), 1);
    for (unsigned i = 0; i < v_int.size(); i++)
        EXPECT_EQ(sequence4[i], v_int[i]);

    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    Person p6("Rui",21);
    Person p7("Vasco",28);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    g.addVertex(p5); g.addVertex(p6); g.addVertex(p7);
    g.addEdge(p1,p2,0);
    g.addEdge(p1,p3,0);
    g.addEdge(p1,p4,0);
    g.addEdge(p2,p5,0);
    g.addEdge(p5,p6,0);
    g.addEdge(p5,p1,0);
    g.addEdge(p3,p6,0);
    g.addEdge(p3,p7,0);
    g.addEdge(p6,p2,0);

    std::vector<Person> v1 = g.bfs(Person("Ana",19));
    std::string names[] = {"Ana", "Carlos", "Filipe", "Ines", "Maria", "Rui", "Vasco"};
    EXPECT_EQ(v1.size(), 7);
    for (unsigned i = 0; i < v1.size(); i++)
        EXPECT_EQ(names[i], v1[i].getName());
}

//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Exercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
TEST(test_2_1_1, nodesAtDistanceDFS) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    Person p6("Rui",21);
    Person p7("Vasco",28);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    g.addVertex(p5); g.addVertex(p6); g.addVertex(p7);
    g.addEdge(p1,p2,0);
    g.addEdge(p1,p3,0);
    g.addEdge(p2,p5,0);
    g.addEdge(p3,p4,0);
    g.addEdge(p5,p6,0);
    g.addEdge(p5,p1,0);
    g.addEdge(p3,p6,0);
    g.addEdge(p3,p7,0);
    g.addEdge(p3,p2,0);

    std::vector<Person> v1 = FunWithDFS::nodesAtDistanceDFS(&g, Person("Ana",19), 0);
    EXPECT_EQ(v1.size(), 1);
    for (unsigned i = 0; i < v1.size(); i++){
        EXPECT_EQ(true, std::find_if(v1.begin(), v1.end(), [](Person const &o) {return (o.getName() == "Ana");}) != v1.end());
    }
    v1 = FunWithDFS::nodesAtDistanceDFS(&g, Person("Ana",19), 1);
    std::string names1[] = {"Carlos", "Filipe"};
    EXPECT_EQ(v1.size(), 2);
    for (unsigned i = 0; i < v1.size(); i++){
        string s = names1[i];
        EXPECT_EQ(true, std::find_if(v1.begin(), v1.end(), [s](Person const &o) {return (o.getName() == s);}) != v1.end());
    }

    v1 = FunWithDFS::nodesAtDistanceDFS(&g, Person("Ana",19), 2);
    std::string names2[] = {"Ines", "Maria", "Rui", "Vasco"};
    EXPECT_EQ(v1.size(), 4);
    for (unsigned i = 0; i < v1.size(); i++){
        string s = names2[i];
        EXPECT_EQ(true, std::find_if(v1.begin(), v1.end(), [s](Person const &o) {return (o.getName() == s);}) != v1.end());
    }
}

//=============================================================================
// Subexercise 2.1.2: Nodes at distance k (BFS)
//=============================================================================
TEST(test_2_1_2, nodesAtDistanceBFS) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    Person p6("Rui",21);
    Person p7("Vasco",28);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    g.addVertex(p5); g.addVertex(p6); g.addVertex(p7);
    g.addEdge(p1,p2,0);
    g.addEdge(p1,p3,0);
    g.addEdge(p2,p5,0);
    g.addEdge(p3,p4,0);
    g.addEdge(p5,p6,0);
    g.addEdge(p5,p1,0);
    g.addEdge(p3,p6,0);
    g.addEdge(p3,p7,0);
    g.addEdge(p3,p2,0);



    std::vector<Person> v1 = FunWithBFS::nodesAtDistanceBFS(&g, Person("Ana",19), 0);
    EXPECT_EQ(v1.size(), 1);
    for (unsigned i = 0; i < v1.size(); i++){
        EXPECT_EQ(true, std::find_if(v1.begin(), v1.end(), [](Person const &o) {return (o.getName() == "Ana");}) != v1.end());
    }
    v1 = FunWithBFS::nodesAtDistanceBFS(&g, Person("Ana",19), 1);
    std::string names1[] = {"Carlos", "Filipe"};
    EXPECT_EQ(v1.size(), 2);
    for (unsigned i = 0; i < v1.size(); i++){
        string s = names1[i];
        EXPECT_EQ(true, std::find_if(v1.begin(), v1.end(), [s](Person const &o) {return (o.getName() == s);}) != v1.end());
    }

    v1 = FunWithBFS::nodesAtDistanceBFS(&g, Person("Ana",19), 2);
    std::string names2[] = {"Ines", "Maria", "Rui", "Vasco"};
    EXPECT_EQ(v1.size(), 4);
    for (unsigned i = 0; i < v1.size(); i++){
        string s = names2[i];
        EXPECT_EQ(true, std::find_if(v1.begin(), v1.end(), [s](Person const &o) {return (o.getName() == s);}) != v1.end());
    }
}


//=============================================================================
// Exercise 2.2: Max New Children
//=============================================================================
TEST(test_2_2, maxNewChildren) {
    Graph<Person> g;
    Person p1("Ana",19);
    Person p2("Carlos",33);
    Person p3("Filipe", 20);
    Person p4("Ines", 18);
    Person p5("Maria", 24);
    Person p6("Rui",21);
    Person p7("Vasco",28);
    g.addVertex(p1); g.addVertex(p2);
    g.addVertex(p3); g.addVertex(p4);
    g.addVertex(p5); g.addVertex(p6); g.addVertex(p7);
    g.addEdge(p1,p2,0);
    g.addEdge(p1,p3,0);
    g.addEdge(p2,p5,0);
    g.addEdge(p3,p4,0);
    g.addEdge(p5,p6,0);
    g.addEdge(p5,p1,0);
    g.addEdge(p3,p6,0);
    g.addEdge(p3,p7,0);
    g.addEdge(p3,p2,0);
    Person pt;
    EXPECT_EQ(3, FunWithBFS::maxNewChildren(&g, Person("Ana",19), pt));
    EXPECT_EQ("Filipe", pt.getName());
}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
TEST(test_2_3, isDAG) {
    Graph<int> g;

    for (int i = 0; i <= 5; i++)
        g.addVertex(i);

    g.addEdge(1, 2, 0);
    g.addEdge(2, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(4, 1, 0);
    g.addEdge(5, 1, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 1, 0);
    g.addEdge(0, 4, 0);

    EXPECT_EQ(false, FunWithDFS::isDAG(g));

    g.removeEdge(4, 1);
    g.removeEdge(5, 1);
    g.removeEdge(2, 3);

    EXPECT_EQ(true, FunWithDFS::isDAG(g));

    g.addEdge(1, 4, 0);

    EXPECT_EQ(true, FunWithDFS::isDAG(g));
}