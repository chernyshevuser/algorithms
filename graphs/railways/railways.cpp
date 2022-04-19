#include "railways.h"

namespace graphs_railways {

    using std::vector;
    using std::string;

    void Dfs(const vector<vector<int>> &graph, vector<Colors> &used, int &usedCount, bool &isOptimal, int startVertex) {
        if (!isOptimal) {
            return;
        }

        used[startVertex] = Colors::GRAY;
        usedCount++;

        for (int curVertex: graph[startVertex]) {
            if (used[curVertex] == Colors::GRAY) {
                isOptimal = false;
                return;
            }
            if (used[curVertex] == Colors::WHITE) {
                Dfs(graph, used, usedCount, isOptimal, curVertex);
            }
        }

        used[startVertex] = Colors::BLACK;
    }

    bool CheckOptimality(const vector<vector<int>> &graph) {
        vector<Colors> used(graph.size(), Colors::WHITE);
        int usedCount = 0;
        bool isOptimal = true;
        int startVertex = 1;

        while (usedCount != graph.size() - 1) {
            if (!isOptimal) {
                return isOptimal;
            }
            while (used[startVertex] != Colors::WHITE) {
                startVertex++;
            }
            Dfs(graph, used, usedCount, isOptimal, startVertex);
        }

        return isOptimal;
    }

    void AddRoadsToGraph(vector<vector<int>> &graph, const string &roads, int startVertex) {
        for (int i = 0; i < roads.size(); i++) {
            if (roads[i] == 'B') {
                graph[startVertex].push_back(startVertex + i + 1);
            } else if (roads[i] == 'R') {
                graph[startVertex + i + 1].push_back(startVertex);
            } else {
                std::cerr << "wrong road" << std::endl;
            }
        }
    }


    void RunProgram() {

        using std::cin;
        using std::cout;
        using std::endl;

        int n;
        string roads;

        cin >> n;

        vector<vector<int>> graph(n + 1);

        for (int i = 1; i < n; i++) {
            cin >> roads;
            AddRoadsToGraph(graph, roads, i);
        }

        cout << (CheckOptimality(graph) ? "YES" : "NO") << endl;
    }

}