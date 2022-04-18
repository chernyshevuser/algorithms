#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>


namespace max_spanning_tree {

    using std::vector;
    using std::optional;

    struct EdgePart {
        int to; //конец ребра
        int weight; // вес ребра
    };

    static bool operator<(const EdgePart &lhs, const EdgePart &rhs) {
        return lhs.weight < rhs.weight;
    }

    void AddEdgePool(const vector<vector<EdgePart>> &graph, vector<EdgePart> &heap,
                     const vector<bool> &used, int indToAdd);

    optional<EdgePart> PopMaxNotUsedEdge(const vector<bool> &used, vector<EdgePart> &heap);

    optional<int> GetMaxSpanningTreeWeight(const vector<vector<EdgePart>> &graph);

    void RunProgram();

}