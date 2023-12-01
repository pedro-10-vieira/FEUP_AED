#ifndef SRC_FUNWITHGRAPHS_H
#define SRC_FUNWITHGRAPHS_H

#include "Graph.h"

class FunWithGraphs {
public:
    static int outDegree(const Graph<int> g, const int &v);
    static int inDegree(const Graph<int> g, const int &v);
    static int weightedOutDegree(const Graph<int> g, const int &v);
};



#endif
