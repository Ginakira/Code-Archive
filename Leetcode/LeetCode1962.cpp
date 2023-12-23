// LeetCode 1962 移除石子使总数最小

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
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q(piles.begin(), piles.end());
        for (int i = 0; i < k; ++i) {
            int pile = q.top();
            q.pop();
            q.emplace((pile + 1) / 2);
        }
        int ans = 0;
        while (!q.empty()) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};