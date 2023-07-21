// LeetCode 1499 满足不等式的最大值

#include <algorithm>
#include <array>
#include <limits>
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
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        using PII = pair<int, int>;
        int ans = std::numeric_limits<int>::min();
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            while (!heap.empty() && x - heap.top().second > k) {
                heap.pop();
            }
            if (!heap.empty()) {
                ans = max(ans, x + y - heap.top().first);
            }
            heap.emplace(x - y, x);
        }
        return ans;
    }
};