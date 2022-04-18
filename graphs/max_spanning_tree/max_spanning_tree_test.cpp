#include "max_spanning_tree_test.h"

namespace max_spanning_tree {
    using std::cout;
    using std::endl;

    void TestGetMaxSpanningTreeWeight() {

        using std::vector;
        using std::optional;
        using std::tuple;

        {
            size_t size = 4;
            vector<tuple<int, int, int>> input = {
                    {1, 2, 5},
                    {1, 3, 6},
                    {2, 4, 8},
                    {3, 4, 3},
            };
            int expectedOutput = 19;

            vector<vector<EdgePart>> graph = SubInputFunction(input, size);

            optional<int> answer = GetMaxSpanningTreeWeight(graph);
            AssertEqual(answer.has_value(), true);
            AssertEqual(answer.value(), expectedOutput);
        }
        {
            size_t size = 3;
            vector<tuple<int, int, int>> input = {
                    {1, 2, 1},
                    {1, 2, 2},
                    {2, 3, 1},
            };
            int expectedOutput = 3;

            vector<vector<EdgePart>> graph = SubInputFunction(input, size);

            optional<int> answer = GetMaxSpanningTreeWeight(graph);
            AssertEqual(answer.has_value(), true);
            AssertEqual(answer.value(), expectedOutput);
        }
        {
            size_t size = 0;
            vector<tuple<int, int, int>> input = { {} };

            vector<vector<EdgePart>> graph = SubInputFunction(input, size);

            optional<int> answer = GetMaxSpanningTreeWeight(graph);
            AssertEqual(answer.has_value(), false);
        }
        {
            size_t size = 10;
            vector<tuple<int, int, int>> input = {
                    {9, 10, 4},
                    {2, 2, 4},
                    {4, 2, 8},
                    {10, 5, 3},
                    {1, 10, 6},
                    {7, 4, 2},
                    {10, 10, 6},
                    {3, 7, 4},
                    {8, 9, 4},
                    {8, 10, 7},
                    {6, 10, 10},
                    {2, 8, 8},
                    {3, 8, 1},
                    {3, 10, 3},
                    {9, 5, 8},
                    {10, 10, 2},
                    {1, 8, 1},
                    {10, 1, 5},
                    {3, 6, 10},
                    {9, 10, 8},
            };
            int expectedOutput = 69;

            vector<vector<EdgePart>> graph = SubInputFunction(input, size);

            optional<int> answer = GetMaxSpanningTreeWeight(graph);
            AssertEqual(answer.has_value(), true);
            AssertEqual(answer.value(), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestGetMaxSpanningTreeWeight, "TestGetMaxSpanningTreeWeight");
    }

    vector<vector<EdgePart>> SubInputFunction(const vector<tuple<int, int, int>>& input, size_t size) {
        vector<vector<EdgePart>> graph(size + 1);

        for (const auto& [from, to, weight]: input) {
            if (from != to) {
                graph[from].push_back({to, weight});
                graph[to].push_back({from, weight});
            }
        }

        return graph;
    }

}