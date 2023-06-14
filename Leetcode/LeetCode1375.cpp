// LeetCode 1375 二进制字符串前缀一致的次数

#include <algorithm>
#include <array>
#include <bitset>
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
    int numTimesAllBlue(vector<int>& flips) {
        constexpr int kMaxDigits = 50000;
        bitset<kMaxDigits> bs;
        int ans = 0, cur = 0;
        for (int i = 0; i < flips.size(); ++i) {
            int ind = flips[i] - 1;
            if (bs.test(i)) {
                ++cur;
            }
            bs.set(ind);
            if (ind <= i) {
                ++cur;
            }

            if (cur == i + 1) {
                ++ans;
            }
        }
        return ans;
    }
};

class Solution {
   public:
    int numTimesAllBlue(vector<int>& flips) {
        int max_ind = 0, ans = 0;
        for (int i = 0; i < flips.size(); ++i) {
            max_ind = max(max_ind, flips[i] - 1);
            if (max_ind == i) {
                ++ans;
            }
        }
        return ans;
    }
};