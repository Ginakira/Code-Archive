// LeetCode 3133 数组最后一个元素的最小值

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
    long long minEnd(int n, int x) {
        long long ans = x;
        long long mask = n - 1;
        int i = 0, j = 0;
        while (mask >> j) {
            if (((ans >> i) & 1) == 0) {
                if ((mask >> j) & 1) {
                    ans |= (1LL << i);
                }
                ++j;
            }
            ++i;
        }
        return ans;
    }
};