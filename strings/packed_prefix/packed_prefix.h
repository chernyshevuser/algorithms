#pragma once

#include <iostream>
#include <memory>
#include <optional>

namespace strings_packed_prefix {

    using std::string;
    using std::cout;
    using std::cin;
    using std::optional;
    using std::istringstream;

    class Prefix {
    public:

        Prefix() = default;

        void AddWord(const string &word);

        string GetSmallestPrefix();

    private:
        optional<string> prefix_;
    };

    string ComputeStringPart(const string &packedString, int &startPos);

    string ComputeUnpackedString(const string &packedString);

    void RunProgram();

}