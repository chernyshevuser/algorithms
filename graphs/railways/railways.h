#pragma once

#include <iostream>
#include <vector>


namespace graphs_railways {

    using std::vector;
    using std::string;

    enum class Colors {
        WHITE,
        GRAY,
        BLACK,
    };

    void Dfs(const vector<vector<int>> &graph, vector<Colors> &used, int &usedCount, bool &isOptimal, int startVertex);

    bool CheckOptimality(const vector<vector<int>> &graph);

    void AddRoadsToGraph(vector<vector<int>> &graph, const string &roads, int startVertex);

    void RunProgram();
}