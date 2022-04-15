#include "packed_prefix_test.h"

namespace strings_packed_prefix {

    void TestComputeUnpackedString() {
        {
            string input = "2[a]2[ab]";
            string expectedOutput = "aaabab";
            AssertEqual(ComputeUnpackedString(input), expectedOutput);
        }
        {
            string input = "3[a]2[r2[t]]";
            string expectedOutput = "aaarttrtt";
            AssertEqual(ComputeUnpackedString(input), expectedOutput);
        }
        {
            string input = "a2[aa3[b]]";
            string expectedOutput = "aaabbbaabbb";
            AssertEqual(ComputeUnpackedString(input), expectedOutput);
        }
    }

    void TestComputePrefix() {
        {
            vector<string> packedStrings = {
                    "2[a]2[ab]",
                    "3[a]2[r2[t]]",
                    "a2[aa3[b]]"
            };
            string expectedOutput = "aaa";

            Prefix prefix;
            for (const auto &packedString: packedStrings) {
                prefix.AddWord(ComputeUnpackedString(packedString));
            }

            AssertEqual(prefix.GetSmallestPrefix(), expectedOutput);
        }
        {
            vector<string> packedStrings = {
                    "abacabaca",
                    "2[abac]a",
                    "3[aba]"
            };
            string expectedOutput = "aba";

            Prefix prefix;
            for (const auto &packedString: packedStrings) {
                prefix.AddWord(ComputeUnpackedString(packedString));
            }

            AssertEqual(prefix.GetSmallestPrefix(), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestComputeUnpackedString, "TestComputeUnpackedString");
        tr.RunTest(TestComputePrefix, "TestComputePrefix");
    }

}