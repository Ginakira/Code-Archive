// LeetCode 1090 受标签影响的最大值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels,
                              int numWanted, int useLimit) {
        int n = values.size();
        vector<pair<int, int>> data;
        data.reserve(n);
        for (int i = 0; i < n; ++i) {
            data.emplace_back(values[i], labels[i]);
        }
        sort(data.begin(), data.end(), std::greater<pair<int, int>>());
        unordered_map<int, int> lable_cnt;

        int ans = 0;
        int cnt = 0;
        for (auto& [value, label] : data) {
            if (cnt >= numWanted) {
                break;
            }
            if (lable_cnt[label] >= useLimit) {
                continue;
            }
            ans += value;
            ++lable_cnt[label];
            ++cnt;
        }
        return ans;
    }
};