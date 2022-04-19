#include "railways_test.h"

namespace graphs_railways {

    using std::vector;
    using std::string;

    void TestCheckOptimality() {
        {
            int vertexCount = 3;
            vector<string> input = {
                    "RB",
                    "R"
            };
            bool expectedOutput = false;

            vector<vector<int>> graph(vertexCount + 1);

            for (int i = 0; i < input.size(); i++) {
                AddRoadsToGraph(graph, input[i], i);
            }

            AssertEqual(CheckOptimality(graph), expectedOutput);
        }
        {
            int vertexCount = 4;
            vector<string> input = {
                    "BBB",
                    "RB",
                    "B"
            };
            bool expectedOutput = true;

            vector<vector<int>> graph(vertexCount + 1);

            for (int i = 0; i < input.size(); i++) {
                AddRoadsToGraph(graph, input[i], i);
            }

            AssertEqual(CheckOptimality(graph), expectedOutput);
        }
        {
            int vertexCount = 5;
            vector<string> input = {
                    "RRRB",
                    "BRR",
                    "BR",
                    "R"
            };
            bool expectedOutput = false;

            vector<vector<int>> graph(vertexCount + 1);

            for (int i = 0; i < input.size(); i++) {
                AddRoadsToGraph(graph, input[i], i);
            }

            AssertEqual(CheckOptimality(graph), expectedOutput);
        }
        {
            int n = 10;
            vector<string> input = {
                    "RRBRRBRRR",
                    "BBBBBBRB",
                    "BBRBRRR",
                    "RRBRRR",
                    "RBRRR",
                    "BBRR",
                    "RRR",
                    "RR",
                    "B"
            };
            bool expectedOutput = true;

            vector<vector<int>> graph(n + 1);

            for (int i = 0; i < input.size(); i++) {
                AddRoadsToGraph(graph, input[i], i);
            }

            AssertEqual(CheckOptimality(graph), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestCheckOptimality, "TestCheckOptimality");
    }

}