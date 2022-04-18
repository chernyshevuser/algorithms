#pragma once

#include "max_spanning_tree.h"
#include "../../test_runner/test_runner.h"
#include <tuple>
#include <iostream>

namespace max_spanning_tree {

    using std::vector;
    using std::tuple;

    void TestGetMaxSpanningTreeWeight();

    void TestAll();

    vector<vector<EdgePart>> SubInputFunction(const vector<tuple<int, int, int>>& input, size_t size);

}
