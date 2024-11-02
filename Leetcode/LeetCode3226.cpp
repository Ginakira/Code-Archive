// LeetCode 3226 使两个整数相等的位更改次数

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
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if ((k & 1) && !(n & 1)) {
                return -1;
            }
            if (!(k & 1) && (n & 1)) {
                ++ans;
            }
            n >>= 1;
            k >>= 1;
        }
        return ans;
    }
};