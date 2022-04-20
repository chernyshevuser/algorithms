#include "sum_of_16_test.h"

namespace sum_of_16 {
    using std::string;

    void TestConvert10to16() {
        {
            int input = 0;
            string expectedOutput = "0";

            AssertEqual(Convert10to16(input), expectedOutput);
        }
        {
            int input = 7;
            string expectedOutput = "7";

            AssertEqual(Convert10to16(input), expectedOutput);
        }
        {
            int input = 10;
            string expectedOutput = "A";

            AssertEqual(Convert10to16(input), expectedOutput);
        }
        {
            int input = 15;
            string expectedOutput = "F";

            AssertEqual(Convert10to16(input), expectedOutput);
        }
        {
            int input = 12349;
            string expectedOutput = "303D";

            AssertEqual(Convert10to16(input), expectedOutput);
        }
        {
            int input = 123;
            string expectedOutput = "7B";

            AssertEqual(Convert10to16(input), expectedOutput);
        }
        {
            int input = 312;
            string expectedOutput = "138";

            AssertEqual(Convert10to16(input), expectedOutput);
        }

    }

    void TestConvert16to10() {
        using std::string;
        {
            string input = "0";
            int expectedOutput = 0;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
        {
            string input = "7";
            int expectedOutput = 7;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
        {
            string input = "A";
            int expectedOutput = 10;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
        {
            string input = "F";
            int expectedOutput = 15;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
        {
            string input = "303D";
            int expectedOutput = 12349;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
        {
            string input = "7B";
            int expectedOutput = 123;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
        {
            string input = "138";
            int expectedOutput = 312;

            AssertEqual(Convert16to10(input), expectedOutput);
        }
    }

    void TestGetSum() {
        using std::string;

        {
            string inputFirst = Convert10to16(0);
            string inputSecond = Convert10to16(0);
            string expectedOutput = Convert10to16(0);

            AssertEqual(GetSum(inputFirst, inputSecond), expectedOutput);
        }
        {
            string inputFirst = Convert10to16(0);
            string inputSecond = Convert10to16(3);
            string expectedOutput = Convert10to16(3);

            AssertEqual(GetSum(inputFirst, inputSecond), expectedOutput);
        }
        {
            string inputFirst = Convert10to16(10);
            string inputSecond = Convert10to16(0);
            string expectedOutput = Convert10to16(10);

            AssertEqual(GetSum(inputFirst, inputSecond), expectedOutput);
        }
        {
            string inputFirst = Convert10to16(123);
            string inputSecond = Convert10to16(6);
            string expectedOutput = Convert10to16(129);

            AssertEqual(GetSum(inputFirst, inputSecond), expectedOutput);
        }
        {
            string inputFirst = Convert10to16(13);
            string inputSecond = Convert10to16(15);
            string expectedOutput = Convert10to16(28);

            AssertEqual(GetSum(inputFirst, inputSecond), expectedOutput);
        }
        {
            string inputFirst = Convert10to16(16);
            string inputSecond = Convert10to16(16);
            string expectedOutput = Convert10to16(32);

            AssertEqual(GetSum(inputFirst, inputSecond), expectedOutput);
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestConvert10to16, "TestConvert10to16");
        tr.RunTest(TestConvert16to10, "TestConvert16to10");
        tr.RunTest(TestGetSum, "TestGetSum");
    }

}