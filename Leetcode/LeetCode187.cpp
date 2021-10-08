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
        vector<string> ans;
        for (int i = 0; i <= n - 10; ++i) {
            string cur = s.substr(i, 10);
            if (mp[cur] == 1) {
                ans.push_back(cur);
            }
            mp[cur]++;
        }
        return ans;
    }
};