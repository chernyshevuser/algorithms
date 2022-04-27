#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <list>
#include <functional>

namespace hash_simple_hash_table {
    using std::string;
    using std::pair;
    using std::list;
    using std::vector;
    using std::optional;
    using std::istream;


    static const int MAX_VECTOR_SIZE = 1e6;


    struct InputCommand {
        string commandWord_;
        int key_;
        int value_;
    };


    istream &operator>>(istream &in, InputCommand &inputCommand);


    class HashMap {
    public:
        HashMap(int maxVectorSize);

        int GetHash(int key);

        void PutValue(int key, int value);

        optional<int> GetValue(int key);

        optional<int> DeleteValue(int key);

    private:
        vector<list<pair<int, int>>> hashMap_;
    };


    void RunProgram();

}