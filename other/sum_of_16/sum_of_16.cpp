#include "sum_of_16.h"

namespace sum_of_16 {

    using std::map;
    using std::string;
    using std::min;
    using std::reverse;

    map<int, char> GetDigits10to16() {
        map<int, char> digits10to16 = {
                {0, '0'},
                {1, '1'},
                {2, '2'},
                {3, '3'},
                {4, '4'},
                {5, '5'},
                {6, '6'},
                {7, '7'},
                {8, '8'},
                {9, '9'},
                {10, 'A'},
                {11, 'B'},
                {12, 'C'},
                {13, 'D'},
                {14, 'E'},
                {15, 'F'},
        };
        return digits10to16;
    }

    map<char, int> GetDigits16to10(const map<int, char>& digits10to16) {
        map<char, int> digits16to10;
        for (const auto& [key, value] : digits10to16) {
            digits16to10[value] = key;
        }
        return digits16to10;
    }

    char ComputeNextSymbol(const map<int, char>& digits10to16, const map<char, int>& digits16to10,
                           const char& firstValue, const char& secondValue, bool& additionalOne,
                           const int BASE) {

        int curSum = digits16to10.at(firstValue) + digits16to10.at(secondValue);

        if (additionalOne) {
            curSum++;
        }

        char nextSymbol = digits10to16.at(curSum % BASE);
        if (curSum - BASE > 0) {
            additionalOne = true;
        }
        else {
            additionalOne = false;
        }

        return nextSymbol;
    }

    string GetSum(string& first, string& second) {
        if (first.size() < second.size()) {
            return GetSum(second, first);
        }
        map<int, char> digits10to16 = GetDigits10to16();
        map<char, int> digits16to10 = GetDigits16to10(digits10to16);

        reverse(first.begin(), first.end());
        reverse(second.begin(), second.end());

        string sum;

        bool additionalOne = false;
        for (int i = 0; i < min(first.size(), second.size()); i++) {
            char firstValue = first[i];
            char secondValue = second[i];

            sum += ComputeNextSymbol(digits10to16, digits16to10, firstValue, secondValue, additionalOne, BASE);
        }

        for (int i = second.size(); i < first.size(); i++) {
            char firstValue = first[i];
            char secondValue = '0';

            sum += ComputeNextSymbol(digits10to16, digits16to10, firstValue, secondValue, additionalOne, BASE);
        }

        if (additionalOne) {
            sum += "1";
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }

    string Convert10to16(int value) {
        if (value == 0) {
            return "0";
        }

        map<int, char> digits10to16 = GetDigits10to16();
        string answer;

        while (value > 0) {
            if (value > 15) {
                int modulo = value - value / BASE * BASE;
                answer += digits10to16.at(modulo);
                value = value / BASE;
            }
            else {
                answer += digits10to16.at(value);
                value = 0;
            }
        }

        reverse(answer.begin(), answer.end());

        return answer;
    }

    int Convert16to10(string& value) {
        reverse(value.begin(), value.end());
        int answer = 0;
        int pow = 1;
        map<char, int> digits16to10 = GetDigits16to10(GetDigits10to16());

        for (const auto& digit: value) {
            answer += digits16to10.at(digit) * pow;
            pow *= 16;
        }

        return answer;
    }

    void RunProgram() {

        using std::cin;
        using std::cout;
        using std::endl;

        int first, second;

        cin >> first >> second;
        string firstStr = Convert10to16(first);
        string secondStr = Convert10to16(second);

        string sum = GetSum(firstStr, secondStr);
        cout << Convert16to10(sum) << endl;
    }

}