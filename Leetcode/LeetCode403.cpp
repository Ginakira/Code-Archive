// LeetCode 403 青蛙过河
#include <unordered_map>
#include <vector>
using namespace std;

// DFS 超时
class Solution {
   private:
    unordered_map<int, int> stones_mark;

    bool helper(vector<int>& stones, int current, int last_steps) {
        if (current == stones.size() - 1) return true;
        for (int i = -1; i <= 1; ++i) {
            int steps = last_steps + i;
            if (steps <= 0) continue;
            if (stones_mark.find(stones[current] + steps) ==
                stones_mark.end()) {
                continue;
            }
            if (helper(stones, stones_mark[stones[current] + steps], steps)) {
                return true;
            }
        }
        return false;
    }

   public:
    bool canCross(vector<int>& stones) {
        for (int i = 0; i < stones.size(); ++i) {
            stones_mark[stones[i]] = i;
        }
        return helper(stones, 0, 0);
    }
};

// DFS + 记忆化 92ms
class Solution2 {
   private:
    unordered_map<int, int> stones_mark;
    vector<unordered_map<int, int>> memory;

    bool helper(vector<int>& stones, int current, int last_steps) {
        if (current == stones.size() - 1) return true;
        if (memory[current].find(last_steps) != memory[current].end()) {
            return memory[current][last_steps];
        }
        for (int i = -1; i <= 1; ++i) {
            int steps = last_steps + i;
            if (steps <= 0) continue;
            if (stones_mark.find(stones[current] + steps) ==
                stones_mark.end()) {
                continue;
            }
            if (helper(stones, stones_mark[stones[current] + steps], steps)) {
                return memory[current][last_steps] = true;
            }
        }
        return memory[current][last_steps] = false;
    }

   public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        for (int i = 0; i < n; ++i) {
            stones_mark[stones[i]] = i;
        }
        memory.resize(n);
        return helper(stones, 0, 0);
    }
};

// DP 156ms
// dp[当前所处的位置][上一次跳跃的步数]
class Solution3 {
   public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        dp[0][0] = true;
        for (int i = 1; i < n; ++i) {
            if (stones[i] - stones[i - 1] > i) {
                return false;
            }
        }
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int k = stones[i] - stones[j];
                if (k > j + 1) {
                    break;
                }
                dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                if (i == n - 1 && dp[i][k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
