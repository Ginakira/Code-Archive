// LeetCode 3066 超过阈值的最少操作数 II

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
    int minOperations(vector<int> &nums, int k) {
        int res = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq(
            nums.begin(), nums.end());
        while (pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x + x + y);
            res++;
        }
        return res;
    }
};