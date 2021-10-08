// LeetCode 187 重复的DNA序列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> mp;
        string cur = s.substr(0, 10);
        vector<string> ans;
        mp[cur]++;
        for (int i = 10; i < n; ++i) {
            cur.erase(0, 1);
            cur.push_back(s[i]);
            if (mp[cur] == 1) {
                ans.push_back(cur);
            }
            mp[cur]++;
        }
        return ans;
    }
};