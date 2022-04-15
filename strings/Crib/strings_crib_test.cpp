#include "strings_crib_test.h"

namespace strings_crib {
    using std::vector;
    using std::string;


    void TestIsPossiblePartition() {
        {
            string text = "examiwillpasstheexam";
            vector<string> words = {
                    "will",
                    "pass",
                    "the",
                    "exam",
                    "i"
            };
            bool expectedOutput = true;

            Crib crib(text);
            for (auto &word: words) {
                crib.AddWord(word);
            }

            AssertEqual(crib.IsPossiblePartition(), expectedOutput);
        }
        {
            string text = "abacaba";
            vector<string> words = {
                    "abac",
                    "caba"
            };
            bool expectedOutput = false;

            Crib crib(text);
            for (auto &word: words) {
                crib.AddWord(word);
            }

            AssertEqual(crib.IsPossiblePartition(), expectedOutput);
        }
        {
            string text = "abacaba";
            vector<string> words = {
                    "abac",
                    "caba",
                    "aba"
            };
            bool expectedOutput = true;

            Crib crib(text);
            for (auto &word: words) {
                crib.AddWord(word);
            }

            AssertEqual(crib.IsPossiblePartition(), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestIsPossiblePartition, "TestIsPossiblePartition");
    }

}