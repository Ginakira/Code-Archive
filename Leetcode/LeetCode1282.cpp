// LeetCode 1282 用户分组
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); ++i) {
            mp[groupSizes[i]].emplace_back(i);
        }
        vector<vector<int>> ans;
        for (auto& [cnt, ids] : mp) {
            for (int i = 0; i < ids.size();) {
                vector<int> group(cnt);
                for (int j = 0; j < cnt; ++j) {
                    group[j] = ids[i];
                    ++i;
                }
                ans.emplace_back(move(group));
            }
        }
        return ans;
    }
};