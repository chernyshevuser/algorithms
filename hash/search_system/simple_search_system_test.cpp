#include "simple_search_system_test.h"

namespace simple_search_system {

    vector<int> WorkEmulation(const vector<string>& input, const vector<string>& request) {
        using std::ostream;
        using std::vector;
        using std::string;
        using std::set;
        using std::map;
        using std::pair;
        using std::stringstream;
        using std::variant;
        using std::get;
        using std::to_string;


        int textCount = input.size(), requestNumber = request.size();
        string inputStr;
        vector<vector<string>> allText;
        set<string> requestWords;
        vector<int> topRelevance;
        vector<int> answer;

        for (int i = 0; i < textCount; i++) {
            inputStr.clear();
            inputStr = input[i];
            variant<set<string>, vector<string>> words = ParseString(inputStr,
                                                                     SetVectorConst:: VECTOR_CONST);
            allText.push_back(get<vector<string>>(words));
        }

        map<string, vector<pair<int, int>>> wordFreqAll = ComputeWordFreqAll(allText);

        for (int i = 0; i < requestNumber; i++) {
            inputStr.clear();
            inputStr = request[i];
            variant<set<string>, vector<string>> words = ParseString(inputStr,
                                                                     SetVectorConst:: SET_CONST);
            requestWords = get<set<string>>(words);
            topRelevance = GetTopRelevanceVec(wordFreqAll, requestWords);
            if (!topRelevance.empty()) {
                for (const auto& tmp: topRelevance) {
                    answer.push_back(tmp);
                }
            }
        }

        return answer;
    }

    void TestSimpleSearchSystem() {
        using std::vector;

        {
            vector<string> input = {
                    "i love coffee",
                    "coffee with milk and sugar",
                    "free tea for everyone"
            };
            vector<string> request = {
                    "i like black coffee without milk",
                    "everyone loves new year",
                    "mary likes black coffee without milk"
            };

            vector<int> expectedOutput = {1, 2, 3, 2, 1};

            AssertEqual(expectedOutput, WorkEmulation(input, request));
        }
        {
            vector<string> input = {
                    "buy flat in moscow",
                    "rent flat in moscow",
                    "sell flat in moscow",
                    "want flat in moscow like crazy",
                    "clean flat in moscow on weekends",
                    "renovate flat in moscow"
            };
            vector<string> request = {
                    "flat in moscow for crazy weekends"
            };

            vector<int> expectedOutput = {4, 5, 1, 2, 3};

            AssertEqual(expectedOutput, WorkEmulation(input, request));
        }
        {
            vector<string> input = {
                    "i like dfs and bfs",
                    "i like dfs dfs",
                    "i like bfs with bfs and bfs"
            };
            vector<string> request = {
                    "dfs dfs dfs dfs bfs"
            };

            vector<int> expectedOutput = {3, 1, 2};

            AssertEqual(expectedOutput, WorkEmulation(input, request));
        }
    }

    void TestAll() {
        TestRunner tr;
        tr.RunTest(TestSimpleSearchSystem, "TestSimpleSearchSystem");
    }

}