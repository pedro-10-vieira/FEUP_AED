#include "funWithGraphs.h"

//=============================================================================
// Exercise 2.1: Connected Components
//=============================================================================
// TODO
void dfsVisit(Vertex<int> *v);
int funWithGraphs::connectedComponents(Graph<int> *g) {
    int res = 0;
    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
    }
    for (auto v : g->getVertexSet()) {
        if (!v->isVisited()) {
            res++;
            dfsVisit(v);
        }
    }
    return res;
}

void dfsVisit(Vertex<int> *v) {
    v->setVisited(true);
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if (!w->isVisited()) {
            dfsVisit(w);
        }
    }
}


//=============================================================================
// Exercise 2.2: Giant Component
//=============================================================================
// TODO
int dfsGC(Vertex<int> *v);
int funWithGraphs::giantComponent(Graph<int> *g) {
    int res = 0;
    for (auto v : g->getVertexSet()) {
        v->setVisited(false);
    }
    for (auto v : g->getVertexSet()) {
        if (!v->isVisited()) {
            res = max(res, dfsGC(v));
        }
    }
    return res;
}

int dfsGC(Vertex<int> *v) {
    int res = 1;
    v->setVisited(true);
    for (auto & e : v->getAdj()) {
        auto w = e.getDest();
        if (!w->isVisited()) {
            res += dfsGC(w);
        }
    }
    return res;
}


//=============================================================================
// Exercise 2.3: Strongly Connected Components
//=============================================================================
// TODO
void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i);
bool inStack(int n, stack<int> s);
list<list<int>> funWithGraphs::scc(Graph<int> *g){
    list<list<int>> res;
    int index = 1;
    stack<int> aux;
    for(auto v : g->getVertexSet()){
        v->setNum(0);
        v->setLow(0);
    }
    for(auto v : g->getVertexSet()){
        if(!v->getNum()) dfs_scc(g,v,aux,res,index);
    }
    return res;

}

void dfs_scc(Graph<int> *g, Vertex<int> *v, stack<int> &s, list<list<int>> &l, int &i){
    v->setLow(i);
    v->setNum(i);
    i++;
    s.push(v->getInfo());
    for(Edge<int> e : v->getAdj()){
        if(!e.getDest()->getNum()) {
            dfs_scc(g, e.getDest(), s, l, i);
            v->setLow(min(v->getLow(), e.getDest()->getLow()));
        }
        else if(inStack(e.getDest()->getInfo(),s)){
            v->setLow(min(v->getLow(),e.getDest()->getNum()));
        }
    }
    if(v->getLow() == v->getNum()){
        list<int> scc;
        int w;
        do {
            w = s.top();
            scc.push_back(w);
            s.pop();
        } while (w != v->getInfo());
        l.push_back(scc);
    }
}

bool inStack(int n, stack<int> s) {
    while (!s.empty() && s.top() != n)
        s.pop();
    if (!s.empty())
        return true;
    return false;
}


//=============================================================================
// Exercise 2.4: Articulation Points
//=============================================================================
// TODO
void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &res, int &i);
unordered_set<int> funWithGraphs::articulationPoints(Graph<int> *g) {
    unordered_set<int> res;

    return res;
}

void dfs_art(Graph<int> *g, Vertex<int> *v, stack<int> &s, unordered_set<int> &l, int &i){}