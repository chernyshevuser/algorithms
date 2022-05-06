#include "simple_search_system.h"

namespace simple_search_system {
    using std::ostream;
    using std::vector;
    using std::string;
    using std::set;
    using std::map;
    using std::pair;
    using std::stringstream;
    using std::variant;
    using std::make_pair;
    using std::get;


    ostream& operator<< (ostream& out, const vector<int>& vec) {
        for (int i = 0; i < vec.size(); i++) {
            out << vec[i];
            if (i != vec.size() - 1) {
                out << " ";
            }
        }
        return out;
    }


    variant<set<string>, vector<string>> ParseString(const string& s, SetVectorConst setVectorConst) {
        vector<string> resVector;
        set<string> resSet;
        stringstream ss(s);
        string curStr;
        while (ss >> curStr) {
            if (setVectorConst == SetVectorConst:: VECTOR_CONST) {
                resVector.push_back(curStr);
            }
            else {
                resSet.insert(curStr);
            }
        }
        if (setVectorConst == SetVectorConst:: VECTOR_CONST) {
            return resVector;
        }
        return resSet;
    }


    //{word -> freq}
    map<string, int> ComputeWordFreqText(const vector<string>& text) {
        map<string, int> wordFreq;
        for (const string& word: text) {
            wordFreq[word]++;
        }
        return wordFreq;
    }


    //{word -> [<freq, textInd>]}
    map<string, vector<pair<int, int>>> ComputeWordFreqAll(const vector<vector<string>>& allText) {
        map<string, vector<pair<int, int>>> wordFreqAll;
        for (int textInd = 0; textInd < allText.size(); textInd++) {
            const vector<string>& curText = allText[textInd];
            map<string, int> WordFreqText = ComputeWordFreqText(curText);
            for (const auto& [word, freq]: WordFreqText) {
                wordFreqAll[word].push_back(pair(freq, textInd + 1));
            }
        }
        return wordFreqAll;
    }


    // {textInd -> value}
    map<int, int> ComputeRelevanceMap(const map<string, vector<pair<int, int>>>& wordFreqAll,
                                      const set<string>& requestWords) {
        map<int, int> relevance;
        for (const string& word: requestWords) {
            auto it = wordFreqAll.find(word);
            if (it != wordFreqAll.end()) {
                const vector<pair<int, int>>& wordInfo = it->second;
                for (const auto& [value, textInd]: wordInfo) {
                    if (!relevance.count(textInd)) {
                        relevance[textInd] = 0;
                    }
                    relevance[textInd] += value;
                }
            }
        }
        return relevance;
    }


    //[value -> textInd]
    vector<pair<int, int>> ComputeRelevanceVec(const map<int, int>& relevance) {
        vector<pair<int, int>> relevanceVec;
        for (const auto& [textInd, value]: relevance) {
            relevanceVec.push_back(make_pair(-value, textInd));
        }
        sort(relevanceVec.begin(), relevanceVec.end());
        return relevanceVec;
    }


    // [textInd]
    vector<int> GetTopRelevanceVec(const map<string, vector<pair<int, int>>>& wordFreqAll,
                                   const set<string>& requestWords) {
        vector<int> topRelevance;
        map<int, int> relevanceMap = ComputeRelevanceMap(wordFreqAll, requestWords);
        vector<pair<int, int>> relevanceVec = ComputeRelevanceVec(relevanceMap);
        int i = 0;
        while (i < relevanceVec.size() and i < 5) {
            topRelevance.push_back(relevanceVec[i].second);
            i++;
        }
        return topRelevance;
    }


    void RunProgram() {
        using std::cin;
        using std::cout;
        using std::endl;

        int textCount, requestNumber;
        string inputStr;
        vector<vector<string>> allText;
        set<string> requestWords;
        vector<int> topRelevance;

        cin >> textCount;
        // убираю первый пробел, возможно, нужно это сделать элегентнее
        getline(cin, inputStr);
        for (int i = 0; i < textCount; i++) {
            inputStr.clear();
            getline(cin, inputStr);
            variant<set<string>, vector<string>> words = ParseString(inputStr,
                                                                     SetVectorConst:: VECTOR_CONST);
            allText.push_back(get<vector<string>>(words));
        }

        map<string, vector<pair<int, int>>> wordFreqAll = ComputeWordFreqAll(allText);

        cin >> requestNumber;
        getline(cin, inputStr);
        bool isFirst = true;
        for (int i = 0; i < requestNumber; i++) {
            inputStr.clear();
            getline(cin, inputStr);
            variant<set<string>, vector<string>> words = ParseString(inputStr,
                                                                     SetVectorConst:: SET_CONST);
            requestWords = get<set<string>>(words);
            topRelevance = GetTopRelevanceVec(wordFreqAll, requestWords);
            if (!topRelevance.empty()) {
                if (!isFirst) {
                    cout << endl;
                }
                isFirst = false;
                cout << topRelevance;
            }
        }
    }

}