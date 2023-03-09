// LeetCode 2379 得到 K 个黑块的最少涂色次数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int left = 0, right = 0;
        int w_cnt = 0;
        int ans = 0;
        while (right < k) {
            w_cnt += blocks[right] == 'W' ? 1 : 0;
            ++right;
        }
        ans = w_cnt;
        while (right < n) {
            w_cnt -= blocks[left] == 'W' ? 1 : 0;
            w_cnt += blocks[right] == 'W' ? 1 : 0;
            ans = min(ans, w_cnt);
            ++left;
            ++right;
        }
        return ans;
    }
};