#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool matched(const unordered_set<string> &dict, const string &str) {
    for (auto word : dict) {
        if (str.find(word) != string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    int x;
    string str;
    cin >> x;
    unordered_set<string> dict;
    for (int i = 0; i < x; ++i) {
        cin >> str;
        dict.insert(str);
    }
    int y;
    cin >> y;
    for (int i = 0; i < y; ++i) {
        cin >> str;
        cout << (matched(dict, str) ? "yes" : "no") << endl;
    }
    return 0;
}