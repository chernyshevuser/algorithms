#pragma once

#include <iostream>
#include <vector>
#include <set>
#include <map>

namespace strings_crib {

    using std::vector;
    using std::string;
    using std::map;
    using std::set;
    using std::pair;


    class HashOperations {
    public:
        static const long long BASE = 123;
        static const long long MODULE = 1e9 + 7;

        HashOperations(int maxSize);

        vector<long long> ComputePrefixHash(const string &s);

        long long ComputeSingleHash(const string &word);

        long long GetHash(const vector<long long> &prefix, int l, int r);

    private:
        vector<long long> prefixPower_;
    };


    class Crib : public HashOperations {
    public:
        struct Word {
            long long hash;
            size_t len;
        };

        friend bool operator<(const Word &lhs, const Word &rhs) {
            return pair(lhs.len, lhs.hash) < pair(rhs.len, rhs.hash);
        }

        Crib(const string &text);

        void AddWord(string &word);

        bool AreEqualStrings(const string &word, int startPos);

        bool IsPossiblePartition();

    private:
        string text_;
        vector<long long> textPrefixHash_;
        map <Word, string> wordsHash_;
        set <size_t> possibleLengths_;
    };


    void RunProgram();

}