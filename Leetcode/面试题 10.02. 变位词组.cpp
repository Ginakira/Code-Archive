// 面试题 10.02. 变位词组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 排序作为key
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const auto& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }

        vector<vector<string>> result;
        for (auto& [_, strs] : mp) {
            result.emplace_back(strs);
        }
        return result;
    }
};