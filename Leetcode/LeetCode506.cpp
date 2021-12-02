// LeetCode 506 相对名次
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 哈希表 16ms
class Solution {
   public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<int> numsSorted = nums;
        sort(numsSorted.rbegin(), numsSorted.rend());
        unordered_map<int, string> numToResult;
        for (int i = 0; i < n; ++i) {
            if (i >= 3) numToResult[numsSorted[i]] = to_string(i + 1);
            if (i == 2) numToResult[numsSorted[i]] = "Bronze Medal";
            if (i == 1) numToResult[numsSorted[i]] = "Silver Medal";
            if (i == 0) numToResult[numsSorted[i]] = "Gold Medal";
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(numToResult[nums[i]]);
        }
        return ans;
    }
};

// 排序
class Solution2 {
   private:
    const vector<string> medals{"Gold Medal", "Silver Medal", "Bronze Medal"};

   public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<tuple<int, int>> sorted_score;
        for (int i = 0; i < score.size(); ++i) {
            sorted_score.emplace_back(score[i], i);
        }
        sort(sorted_score.begin(), sorted_score.end(),
             greater<tuple<int, int>>());

        vector<string> ans(score.size());
        for (int i = 0; i < sorted_score.size(); ++i) {
            auto [val, seq] = sorted_score[i];
            if (i < 3) {
                ans[seq] = medals[i];
            } else {
                ans[seq] = to_string(i + 1);
            }
        }
        return ans;
    }
};