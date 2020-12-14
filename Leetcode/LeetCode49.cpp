// LeetCode 49 字母异位词分组
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

// Solution1: 76ms 19.7MB
// 使用排序结果作为异位词的key
class Solution1 {
   public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        map<string, vector<string>> mp;
        for (const string &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto &it : mp) {
            ret.emplace_back(it.second);
        }
        return ret;
    }
};