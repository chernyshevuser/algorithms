#include "strings_crib.h"

namespace strings_crib {

    using std::vector;
    using std::string;
    using std::map;
    using std::set;

    HashOperations::HashOperations(int maxSize) {
        vector<long long> prefixPower(maxSize);
        prefixPower[0] = 1;
        for (int i = 1; i < maxSize; i++) {
            prefixPower[i] = (prefixPower[i - 1] * (BASE % MODULE)) % MODULE;
        }
        prefixPower_ = prefixPower;
    }

    vector<long long> HashOperations::ComputePrefixHash(const string &s) {
        int n = s.size();
        vector<long long> prefix(n + 1);
        prefix[0] = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] * BASE % MODULE + MODULE) % MODULE + int(s[i]) % MODULE + MODULE;
            prefix[i + 1] %= MODULE;
        }
        return prefix;
    }

    long long HashOperations::ComputeSingleHash(const string &word) {
        long long hash = 0;
        for (int i = 0; i < word.size(); i++) {
            hash = ((hash * BASE % MODULE + MODULE) % MODULE + int(word[i]) % MODULE + MODULE) % MODULE;
        }
        return hash;
    }

    long long HashOperations::GetHash(const vector<long long> &prefix, int l, int r) {
        return ((prefix[r] - (prefix[l - 1] * prefixPower_[r - l + 1]) % MODULE) + MODULE) % MODULE;
    }


    Crib::Crib(const string &text) : HashOperations(text.size()) {
        textPrefixHash_ = ComputePrefixHash(text);
        text_ = text;
    }

    void Crib::AddWord(string &word) {
        if (word.size() + 1 < textPrefixHash_.size()) {
            long long hash = ComputeSingleHash(word);
            size_t len = word.size();

            wordsHash_[{hash, len}] = move(word);
            possibleLengths_.insert(len);
        }
    }

    bool Crib::AreEqualStrings(const string &word, int startPos) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] != text_[startPos + i]) {
                return false;
            }
        }
        return true;
    }

    bool Crib::IsPossiblePartition() {
        vector<bool> dp(textPrefixHash_.size());
        dp[0] = true;

        for (int i = 0; i < dp.size() - 1; i++) {
            auto curLenIt = possibleLengths_.begin();

            while (curLenIt != possibleLengths_.end() and *curLenIt <= i + 1 and !dp[i + 1]) {
                long long textHash = GetHash(textPrefixHash_, i - int(*curLenIt) + 2, i + 1);
                Word tmp = {textHash, *curLenIt};
                if (wordsHash_.count(tmp) != 0 and
                    AreEqualStrings(wordsHash_[tmp], i - int(*curLenIt) + 1)) {
                    dp[i + 1] = dp[i - *curLenIt + 1];
                }
                curLenIt = next(curLenIt);
            }
        }

        return dp[dp.size() - 1];
    }

    using std::cin;
    using std::cout;
    using std::endl;

    void RunProgram() {
        string text;
        string word;
        int n;

        cin >> text;
        cin >> n;

        Crib crib(text);

        for (int i = 0; i < n; i++) {
            cin >> word;
            crib.AddWord(word);
        }

        cout << (crib.IsPossiblePartition() ? "YES" : "NO");
    }

}
