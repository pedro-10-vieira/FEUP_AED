#include "funWithDFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.1: Nodes at distance k (DFS)
//=============================================================================
// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res);

vector<Person> FunWithDFS::nodesAtDistanceDFS(const Graph<Person> *g, const Person &source, int k) {
    vector<Person> res;
    Vertex<Person>* person = g->findVertex(source);
    nodesAtDistanceDFSVisit(g, person, k, res);
    return res;
}

// TODO
void nodesAtDistanceDFSVisit(const Graph<Person> *g, Vertex<Person> *v, int k, vector<Person> &res) {
    if (k == 0) {
        if (!(v->isVisited())) {
            res.push_back(v->getInfo());
        }
        return;
    }

    v->setVisited(true);

    for (Edge<Person> edge : v->getAdj()) {
        nodesAtDistanceDFSVisit(g, edge.getDest(), k - 1, res);
    }
}


//=============================================================================
// Exercise 2.3: Directed Acyclic Graph
//=============================================================================
// TODO
bool dfsIsDAG(Vertex<int> *v);
bool FunWithDFS::isDAG(Graph<int> g) {
    for (auto vt : g.getVertexSet()) {
        vt->setVisited(false);
    }
    for (auto vt : g.getVertexSet()) {
        if (!vt->isVisited()) {
            if (!dfsIsDAG(vt)) {
                return false;
            }
        }
    }
    return true;
}

// TODO
bool dfsIsDAG(Vertex<int> *v) {
    if (v->isVisited()) {
        return false;
    }
    v->setVisited(true);
    for (Edge<int> edge : v->getAdj()) {
        if (!dfsIsDAG(edge.getDest())) {
            return false;
        }
    }
    v->setVisited(false);
    return true;
}
