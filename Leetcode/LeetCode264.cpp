// LeetCode 264 丑数II
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

// set
class Solution {
   public:
    int nthUglyNumber(int n) {
        set<long> s{1};
        for (int i = 2; i <= n; ++i) {
            long val = *s.begin();
            s.erase(s.begin());
            s.insert(val * 2);
            s.insert(val * 3);
            s.insert(val * 5);
        }
        return *s.begin();
    }
};

// 哈希+小顶堆
class Solution2 {
   public:
    int nthUglyNumber(int n) {
        const vector<int> factors = {2, 3, 5};
        unordered_set<long> seen = {1};
        priority_queue<long, vector<long>, greater<long>> nums;
        nums.push(1);
        int ugly = 0;
        for (int i = 0; i < n; ++i) {
            long current = nums.top();
            nums.pop();
            ugly = (int)current;
            for (const int &factor : factors) {
                long next_num = current * factor;
                if (seen.count(next_num)) continue;
                nums.push(next_num);
                seen.insert(next_num);
            }
        }
        return ugly;
    }
};

// 三指针（真想不出来……）
class Solution3 {
   public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        int fac2 = 1, fac3 = 1, fac5 = 1;
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int num2 = dp[fac2] * 2, num3 = dp[fac3] * 3, num5 = dp[fac5] * 5;
            dp[i] = min(num2, min(num3, num5));
            if (dp[i] == num2) {
                ++fac2;
            }
            if (dp[i] == num3) {
                ++fac3;
            }
            if (dp[i] == num5) {
                ++fac5;
            }
        }
        return dp[n];
    }
};