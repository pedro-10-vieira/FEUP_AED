#ifndef SRC_FUNWITHDFS_H
#define SRC_FUNWITHDFS_H

#include "Graph.h"
#include "Person.h"

class FunWithDFS{
public:
    static bool isDAG(Graph<int> g);
    static vector<Person> nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k);
};

#endif
