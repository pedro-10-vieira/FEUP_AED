#include "funWithBFS.h"


//=============================================================================
// Exercise 2.1: Nodes at distance k
//=============================================================================
// Subexercise 2.1.2: Nodes at distance k (BFS)
//=============================================================================
// TODO
vector<Person> FunWithBFS::nodesAtDistanceBFS(const Graph<Person> *g, const Person &source, int k) {
    for (auto vt : g->getVertexSet()) {
        vt->setVisited(false);
    }
    vector<Person> res;
    auto it = g->findVertex(source);
    queue<Vertex<Person>> p_q;
    p_q.push(*it);
    while (!p_q.empty() && k >= 0) {
        size_t queue_size = p_q.size();
        for (size_t i = 0; i < queue_size; i++) {
            Vertex<Person> actual = p_q.front();
            p_q.pop();
            if (k == 0) {
                res.push_back(actual.getInfo());
            }
            for (Edge<Person> edge : actual.getAdj()) {
                if (!(edge.getDest()->isVisited())) {
                    p_q.push(*edge.getDest());
                    edge.getDest()->setVisited(true);
                }
            }
        }
        k--;
    }
    return res;
}

//=============================================================================
// Exercise 2.2: Max New Children
//=============================================================================
// TODO
int FunWithBFS::maxNewChildren(const Graph<Person> *g, const Person &source, Person &info) {
    int res = 0;
    for (auto vt : g->getVertexSet()) {
        vt->setVisited(false);
    }
    auto it = g->findVertex(source);
    it->setVisited(true);
    queue<Vertex<Person>> p_q;
    for (Edge<Person> edge : it->getAdj()) {
        p_q.push(*edge.getDest());
        edge.getDest()->setVisited(true);
    }
    while (!p_q.empty()) {
        int max_children = 0;
        Vertex<Person> actual = p_q.front();
        p_q.pop();
        for (Edge<Person> edge : actual.getAdj()) {
            if (!(edge.getDest()->isVisited())) {
                max_children++;
            }
        }
        if (max_children > res) {
            res = max_children;
            info = actual.getInfo();
        }
    }
    return res;
}
