#include "strings_packed_prefix.h"

namespace strings_packed_prefix {

    using std::string;
    using std::optional;
    using std::cout;
    using std::cin;
    using std::endl;
    using std::istringstream;


    void Prefix::AddWord(const string &word) {
        if (!prefix_.has_value()) {
            prefix_ = word;
            return;
        }

        int pos = 0;
        while (pos < word.size() and pos < prefix_.value().size()) {
            if (word[pos] != prefix_.value()[pos]) {
                prefix_.value().resize(pos);
                return;
            }
            pos++;
        }
    }

    string Prefix::GetSmallestPrefix() {
        return prefix_.value();
    }

    string ComputeStringPart(const string &packedString, int &startPos) {
        string unpackedStringPart;

        while (startPos < packedString.size()) {
            while (startPos < packedString.size() and isalpha(packedString[startPos])) {
                unpackedStringPart += packedString[startPos];
                startPos++;
            }

            if (startPos < packedString.size() and isdigit(packedString[startPos])) {
                int repeatCount = int(packedString[startPos] - '0');
                int lastPos = startPos + 2;

                string repeatingString = ComputeStringPart(packedString, lastPos);
                for (int i = 0; i < repeatCount; i++) {
                    unpackedStringPart += repeatingString;
                }
                startPos = lastPos + 1;
            } else {
                return unpackedStringPart;
            }
        }

        return unpackedStringPart;
    }

    string ComputeUnpackedString(const string &packedString) {
        int startPos = 0;
        return ComputeStringPart(packedString, startPos);
    }

    void RunProgram() {
        Prefix prefix;
        string packedString;
        int n;

        cout << "input packed words count and words" << endl;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> packedString;
            prefix.AddWord(ComputeUnpackedString(packedString));
        }

        cout << "the longest common prefix is '" << prefix.GetSmallestPrefix() << "'" << endl;
    }

}