#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <variant>
#include <utility>
#include <algorithm>

namespace simple_search_system {


    enum class SetVectorConst {
        VECTOR_CONST = 0,
        SET_CONST = 1,
    };


    std::ostream &operator<<(std::ostream &out, const std::vector<int> &vec);


    std::variant<std::set<std::string>, std::vector<std::string>> ParseString(
            const std::string &s, SetVectorConst setVectorConst);


    //{word -> freq}
    std::map<std::string, int> ComputeWordFreqText(const std::vector<std::string> &text);


    //{word -> [<freq, textInd>]}
    std::map<std::string, std::vector<std::pair<int, int>>> ComputeWordFreqAll(
            const std::vector<std::vector<std::string>> &allText);


    // {textInd -> value}
    std::map<int, int> ComputeRelevanceMap(const std::map<std::string, std::vector<std::pair<int, int>>> &wordFreqAll,
                                           const std::set<std::string> &requestWords);


    //[value -> textInd]
    std::vector<std::pair<int, int>> ComputeRelevanceVec(const std::map<int, int> &relevance);


    // [textInd]
    std::vector<int> GetTopRelevanceVec(const std::map<std::string, std::vector<std::pair<int, int>>> &wordFreqAll,
                                        const std::set<std::string> &requestWords);


    void RunProgram();
}
