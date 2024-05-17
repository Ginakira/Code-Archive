// LeetCode 826 安排工作以达到最大收益

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
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        vector<tuple<int, int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = make_tuple(difficulty[i], profit[i]);
        }
        ranges::sort(worker);
        ranges::sort(jobs);
        int ans = 0;
        int i = 0;
        int best = 0;
        for (auto w : worker) {
            while (i < n && get<0>(jobs[i]) <= w) {
                best = max(best, get<1>(jobs[i]));
                ++i;
            }
            ans += best;
        }
        return ans;
    }
};