// LeetCode 2530 执行K次操作后的最大分数

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
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k; ++i) {
            int num = pq.top();
            pq.pop();
            score += num;
            pq.push(ceil(num / 3.0));
        }
        return score;
    }
};
