// LeetCode 868 二进制间距

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int binaryGap(int n) {
        int ans = 0, last_ind = 64, cur_ind = 0, num = n;
        while (num) {
            if (num & 1) {
                ans = max(ans, cur_ind - last_ind);
                last_ind = cur_ind;
            }
            num >>= 1;
            ++cur_ind;
        }
        return ans;
    }
};