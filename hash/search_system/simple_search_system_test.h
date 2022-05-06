#pragma once

#include "simple_search_system.h"
#include "../../test_runner/test_runner.h"
#include <string>


namespace simple_search_system {

    vector<int> WorkEmulation(const vector<string>& input, const vector<string>& request);

    void TestSimpleSearchSystem();

    void TestAll();
}