// LeetCode 2208 将数组和减半的最少操作次数

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
    int halveArray(vector<int>& nums) {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double target = sum / 2.0, cur = 0;
        int cnt = 0;
        priority_queue<double> q(nums.begin(), nums.end());
        while (!q.empty() && cur < target) {
            double num = q.top();
            q.pop();
            num /= 2;
            cur += num;
            q.emplace(num);
            ++cnt;
        }
        return cnt;
    }
};