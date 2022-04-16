#include "levenshtein_distance_test.h"

namespace levenshtein_distance {

    void TestComputeLevenshteinDistance() {
        using std::string;
        {
            string first = "abacaba";
            string second = "abaabc";
            int expectedOutput = 2;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
        {
            string first = "innokentiy";
            string second = "innnokkentia";
            int expectedOutput = 3;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
        {
            string first = "r";
            string second = "x";
            int expectedOutput = 1;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
        {
            string first = "vxeaqlxdky";
            string second = "vkullc";
            int expectedOutput = 8;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
        {
            string first = "lfohxcrhsvvzvrbfithqixlwcyopppqcpvdlpzdafzxajdycqboi";
            string second = "rxchzmcirjsqefkpefbgwstfoqypjpecgpaennadtadnpzdozlgnavtprcfo";
            int expectedOutput = 47;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
        {
            string first = "dxqrpmratn";
            string second = "jdpmykgmaitn";
            int expectedOutput = 8;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
        {
            string first = "dkuqhkufqs";
            string second = "dvihfkuxs";
            int expectedOutput = 6;
            AssertEqual(ComputeLevenshteinDistance(first, second), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestComputeLevenshteinDistance, "TestComputeLevenshteinDistance");
    }

}
