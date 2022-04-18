#include "max_spanning_tree.h"

namespace max_spanning_tree {

    using std::vector;
    using std::optional;

    void AddEdgePool(const vector<vector<EdgePart>> &graph, vector<EdgePart> &heap,
                     const vector<bool> &used, int indToAdd) {
        for (const EdgePart &edgePart: graph[indToAdd]) {
            if (!used[edgePart.to]) {
                heap.push_back(edgePart);
                push_heap(heap.begin(), heap.end());
            }
        }
    }


    optional<EdgePart> PopMaxNotUsedEdge(const vector<bool> &used, vector<EdgePart> &heap) {
        while (!heap.empty()) {
            pop_heap(heap.begin(), heap.end());
            EdgePart edgePart = heap.back();
            heap.pop_back();
            if (!used[edgePart.to]) {
                return edgePart;
            }
        }

        return {};
    }


    optional<int> GetMaxSpanningTreeWeight(const vector<vector<EdgePart>> &graph) {
        vector<EdgePart> heap;
        make_heap(heap.begin(), heap.end());

        vector<bool> used(graph.size(), false);

        int usedVertexCount = 0;
        int startVertex = 1;
        int spanningTreeWeight = 0;

        used[startVertex] = true;
        usedVertexCount++;
        AddEdgePool(graph, heap, used, startVertex);

        while (!heap.empty() or usedVertexCount != graph.size() - 1) {
            optional<EdgePart> nextEdge = PopMaxNotUsedEdge(used, heap);

            if (nextEdge.has_value()) {
                spanningTreeWeight += nextEdge->weight;
                usedVertexCount++;
                used[nextEdge->to] = true;
                AddEdgePool(graph, heap, used, nextEdge->to);
            } else {
                if (usedVertexCount == graph.size() - 1) {
                    return spanningTreeWeight;
                }
                return {};
            }
        }

        return spanningTreeWeight;
    }


    void RunProgram() {
        using std::cin;
        using std::cout;
        using std::endl;

        int n, m, from, to, weight;

        cin >> n >> m;

        vector<vector<EdgePart>> graph(n + 1);

        for (int i = 0; i < m; i++) {
            cin >> from >> to >> weight;
            if (from != to) {
                graph[from].push_back({to, weight});
                graph[to].push_back({from, weight});
            }
        }

        optional<int> maxSpanningTreeWeight = GetMaxSpanningTreeWeight(graph);

        if (maxSpanningTreeWeight.has_value()) {
            cout << maxSpanningTreeWeight.value();
        } else {
            cout << "Oops! I did it again";
        }
        cout << endl;
    }

}