// LeetCode 1807 替换字符串中的括号内容

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (auto& vec : knowledge) {
            dict[vec[0]] = vec[1];
        }

        bool is_key = false;
        string key, res;
        size_t n = s.size();
        for (size_t i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '(') {
                is_key = true;
            } else if (ch == ')') {
                if (dict.count(key)) {
                    res += dict[key];
                } else {
                    res.push_back('?');
                }
                is_key = false;
                key.clear();
            } else {
                if (is_key) {
                    key.push_back(ch);
                } else {
                    res.push_back(ch);
                }
            }
        }
        return res;
    }
};