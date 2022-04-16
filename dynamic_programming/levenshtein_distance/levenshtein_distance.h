#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

namespace levenshtein_distance {

    static int OPERATION_COST = 1;

    int ComputeLevenshteinDistance(const std::string &first, const std::string &second);

    void RunProgram();

}