#pragma once

#include <map>
#include <iostream>
#include <algorithm>

namespace sum_of_16 {

    using std::map;
    using std::string;

    static const int BASE = 16;

    map<int, char> GetDigits10to16();

    map<char, int> GetDigits16to10(const map<int, char>& digits10to16);

    char ComputeNextSymbol(const map<int, char>& digits10to16, const map<char, int>& digits16to10,
                           const char& firstValue, const char& secondValue, bool& additionalOne,
                           const int BASE);

    string GetSum(string& first, string& second);

    string Convert10to16(int value);

    int Convert16to10(string& value);

    void RunProgram();
}











