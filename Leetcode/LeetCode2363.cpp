// LeetCode 2363 合并相似的物品

#include <algorithm>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                          vector<vector<int>> &items2) {
        map<int, int> mp;
        auto helper = [&](const vector<vector<int>> &items) {
            for (auto &item : items) {
                mp[item[0]] += item[1];
            }
        };
        helper(items1);
        helper(items2);
        vector<vector<int>> result;
        result.reserve(mp.size());
        for (auto &[value, weight] : mp) {
            result.push_back({value, weight});
        }
        return result;
    }
};