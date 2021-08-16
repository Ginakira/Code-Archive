// LeetCode 526 优美的排列

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int ans = 0;
    vector<int> used;

    void backtrace(int cur_digit, int cur_index, int n) {
        if (cur_digit % cur_index != 0 && cur_index % cur_digit != 0) return;
        if (cur_index == n) {
            ++ans;
            return;
        }

        for (int i = 1; i <= n; ++i) {
            if (used[i]) continue;
            used[i] = true;
            backtrace(i, cur_index + 1, n);
            used[i] = false;
        }
    }

   public:
    int countArrangement(int n) {
        used.resize(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            used[i] = true;
            backtrace(i, 1, n);
            used[i] = false;
        }
        return ans;
    }
};