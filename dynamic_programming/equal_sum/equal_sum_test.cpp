#include "equal_sum_test.h"

namespace equal_sum {
    void TestIsPossiblePartition() {
        using std::vector;
        {
            vector<int> nums = {1, 5, 7, 1};
            bool expectedOutput = true;
            AssertEqual(IsPossiblePartition(nums), expectedOutput);
        }
        {
            vector<int> nums = {2, 10, 9};
            bool expectedOutput = false;
            AssertEqual(IsPossiblePartition(nums), expectedOutput);
        }
        {
            vector<int> nums = {7, 9, 3, 4, 6, 7};
            bool expectedOutput = true;
            AssertEqual(IsPossiblePartition(nums), expectedOutput);
        }
        {
            vector<int> nums = {1, 9};
            bool expectedOutput = false;
            AssertEqual(IsPossiblePartition(nums), expectedOutput);
        }
        {
            vector<int> nums = {11, 11, 9, 9, 5, 5, 1, 1};
            bool expectedOutput = true;
            AssertEqual(IsPossiblePartition(nums), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestIsPossiblePartition, "TestIsPossiblePartition");
    }
}