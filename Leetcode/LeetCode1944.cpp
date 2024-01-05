// LeetCode 1944 队列中可以看到的人数

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
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> stk;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; --i) {
            int height = heights[i];
            while (!stk.empty() && stk.top() < height) {
                ++ans[i];
                stk.pop();
            }
            if (!stk.empty()) {
                ++ans[i];
            }
            stk.emplace(height);
        }
        return ans;
    }
};