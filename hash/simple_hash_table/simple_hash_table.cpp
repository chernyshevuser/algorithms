#include "simple_hash_table.h"


namespace hash_simple_hash_table {
    using std::string;
    using std::pair;
    using std::list;
    using std::vector;
    using std::optional;
    using std::istream;


    istream &operator>>(istream &in, InputCommand &inputCommand) {
        in >> inputCommand.commandWord_;
        in >> inputCommand.key_;
        if (inputCommand.commandWord_ == "put") {
            in >> inputCommand.value_;
        }
        return in;
    }


    HashMap::HashMap(int maxVectorSize) : hashMap_(maxVectorSize) {}


    int HashMap::GetHash(int key) {
        using std::hash;

        int localHash = hash<int>{}(key);
        return localHash % MAX_VECTOR_SIZE;
    }


    void HashMap::PutValue(int key, int value) {
        int hash = GetHash(key);
        if (hashMap_[hash].empty()) {
            hashMap_[hash].push_front(pair(key, value));
        } else {
            auto it = find_if(hashMap_[hash].begin(), hashMap_[hash].end(), [key](pair<int, int> node) {
                return node.first == key;
            });
            if (it != hashMap_[hash].end()) {
                it->second = value;
            } else {
                hashMap_[hash].push_front(pair(key, value));
            }
        }
    }


    optional<int> HashMap::GetValue(int key) {
        int hash = GetHash(key);
        auto it = find_if(hashMap_[hash].begin(), hashMap_[hash].end(), [key](pair<int, int> node) {
            return node.first == key;
        });
        if (it == hashMap_[hash].end()) {
            return {};
        }
        return it->second;
    }


    optional<int> HashMap::DeleteValue(int key) {
        int hash = GetHash(key);
        auto it = find_if(hashMap_[hash].begin(), hashMap_[hash].end(), [key](pair<int, int> node) {
            return node.first == key;
        });
        if (it == hashMap_[hash].end()) {
            return {};
        }
        int value = it->second;
        hashMap_[hash].erase(it);
        return value;
    }


    void RunProgram() {
        using std::cin;
        using std::cout;
        using std::endl;

        HashMap hashMap(MAX_VECTOR_SIZE);
        int requestNumber;
        InputCommand inputCommand;
        bool isFirstPrint = true;
        cin >> requestNumber;
        for (int i = 0; i < requestNumber; i++) {
            cin >> inputCommand;
            if (inputCommand.commandWord_ == "get" or inputCommand.commandWord_ == "delete") {
                if (!isFirstPrint) {
                    cout << endl;
                }
                isFirstPrint = false;
                optional<int> res;
                if (inputCommand.commandWord_ == "get") {
                    res = hashMap.GetValue(inputCommand.key_);
                } else {
                    res = hashMap.DeleteValue(inputCommand.key_);
                }
                if (res.has_value()) {
                    cout << res.value();
                } else {
                    cout << "None";
                }
            } else if (inputCommand.commandWord_ == "put") {
                hashMap.PutValue(inputCommand.key_, inputCommand.value_);
            } else {
                cout << "WRONG INPUT: " << inputCommand.commandWord_;
            }
        }
        cout << endl;
    }

}