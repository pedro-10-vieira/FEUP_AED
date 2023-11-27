#ifndef SRC_FUNWITHBFS_H
#define SRC_FUNWITHBFS_H

#include "Graph.h"
#include "Person.h"

class FunWithBFS {
public:
    static int maxNewChildren(const Graph<Person> *g, const Person &source, Person &info);
    static vector<Person> nodesAtDistanceBFS(const Graph<Person> *g, const Person &source, int k);
};

#endif
