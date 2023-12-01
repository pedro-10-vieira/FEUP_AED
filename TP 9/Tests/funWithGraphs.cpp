#include "funWithGraphs.h"


//=============================================================================
// Exercise 2: Vertex degrees
//=============================================================================
// Subexercise 2.1: outDegree
//=============================================================================
//TODO
int FunWithGraphs::outDegree(const Graph<int> g, const int &v) {
    auto it = g.findVertex(v);
    if (it == nullptr) {
        return -1;
    }
    return it->getAdj().size();
}


//=============================================================================
// Subexercise 2.2: inDegree
//=============================================================================
//TODO
int FunWithGraphs::inDegree(const Graph<int> g, const int &v) {
    int res = 0;
    auto it1 = g.findVertex(v);
    if (it1 == nullptr) {
        return -1;
    }
    auto v_set = g.getVertexSet();
    for (auto it2 = v_set.begin(); it2 != v_set.end(); it2++) {
        Vertex<int>* vertex = *it2;
        for (Edge<int> edge : vertex->getAdj()) {
            if (edge.getDest() == it1) {
                res++;
            }
        }
    }
    return res;
}

//=============================================================================
// Subexercise 2.3: weightedOutDegree
//=============================================================================
// TODO
int FunWithGraphs::weightedOutDegree(const Graph<int> g, const int &v) {
    int res = 0;
    auto it = g.findVertex(v);
    if (it == nullptr) {
        return -1;
    }
    for (Edge<int> edge : it->getAdj()) {
        res += edge.getWeight();
    }
    return res;
}
