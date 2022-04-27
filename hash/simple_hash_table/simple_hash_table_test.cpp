#include "simple_hash_table_test.h"


namespace hash_simple_hash_table {

    void TestHashMap() {
        int DEFAULT_INT = 0;

        {
            vector<InputCommand> input = {
                    {"get", 1, DEFAULT_INT},
                    {"put", 1, 10},
                    {"put", 2, 4},
                    {"get", 1, DEFAULT_INT},
                    {"get", 2, DEFAULT_INT},
                    {"delete", 2, DEFAULT_INT},
                    {"get", 2, DEFAULT_INT},
                    {"put", 1, 5},
                    {"get", 1, DEFAULT_INT},
                    {"delete", 2, DEFAULT_INT}
            };

            vector<string> expectedOutput = {
                    "None",
                    "10",
                    "4",
                    "4",
                    "None",
                    "5",
                    "None"
            };

            AssertEqual(WorkEmulation(input), expectedOutput);
        }
        {
            vector<InputCommand> input = {
                    {"get", 9, DEFAULT_INT},
                    {"delete", 9, DEFAULT_INT},
                    {"put", 9, 1},
                    {"get", 9, DEFAULT_INT},
                    {"put", 9, 2},
                    {"get", 9, DEFAULT_INT},
                    {"put", 9, 3},
                    {"get", 9, DEFAULT_INT},
            };

            vector<string> expectedOutput = {
                    "None",
                    "None",
                    "1",
                    "2",
                    "3"
            };

            AssertEqual(WorkEmulation(input), expectedOutput);
        }

    }


    vector<string> WorkEmulation(const vector<InputCommand>& commands) {
        using std::string;
        using std::to_string;

        HashMap hashMap(MAX_VECTOR_SIZE);
        vector<string> output;

        for (const auto& inputCommand: commands) {

            if (inputCommand.commandWord_ == "get" or inputCommand.commandWord_ == "delete") {
                optional<int> res;
                if (inputCommand.commandWord_ == "get") {
                    res = hashMap.GetValue(inputCommand.key_);
                } else {
                    res = hashMap.DeleteValue(inputCommand.key_);
                }
                if (res.has_value()) {
                    output.push_back(to_string(res.value()));
                } else {
                    output.emplace_back("None");
                }
            } else if (inputCommand.commandWord_ == "put") {
                hashMap.PutValue(inputCommand.key_, inputCommand.value_);
            } else {
                output.push_back("WRONG INPUT: " + inputCommand.commandWord_);
            }
        }

        return output;
    }


    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestHashMap, "TestHashMap");
    }
}
