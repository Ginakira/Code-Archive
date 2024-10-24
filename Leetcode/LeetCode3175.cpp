// LeetCode 3175 找到连续赢K场比赛的第一位玩家

#include <algorithm>
#include <array>
#include <deque>
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
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n) {
            return distance(skills.begin(), ranges::max_element(skills));
        }
        deque<int> dq(n);
        vector<int> cnt(n, 0);
        ranges::iota(dq, 0);
        while (!dq.empty()) {
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            if (skills[a] < skills[b]) {
                swap(a, b);
            }
            dq.push_front(a);
            dq.push_back(b);
            if (++cnt[a] >= k) {
                return a;
            }
        }
        return -1;
    }
};

class Solution2 {
   public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        int max_i = 0, win = 0;
        for (int i = 1; i < n && win < k; ++i) {
            if (skills[i] > skills[max_i]) {
                win = 0;
                max_i = i;
            }
            ++win;
        }
        return max_i;
    }
};