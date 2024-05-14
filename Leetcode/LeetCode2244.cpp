// LeetCode 2244 完成所有任务需要的最少轮数

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
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (auto& task : tasks) {
            ++cnt[task];
        }
        for (auto [_, c] : cnt) {
            if (c == 1) {
                return -1;
            } else if (c % 3 == 0) {
                ans += c / 3;
            } else {
                ans += c / 3 + 1;
            }
        }
        return ans;
    }
};