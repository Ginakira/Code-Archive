// LeetCode 3233 统计不是特殊数字的数字数量

#include <algorithm>
#include <array>
#include <cmath>
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
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<int> v(n + 1);
        int ans = r - l + 1;
        for (int i = 2; i <= n; ++i) {
            if (v[i] == 0) {
                if (i * i >= l && i * i <= r) {
                    --ans;
                }
                for (int j = i * 2; j <= n; j += i) {
                    v[j] = 1;
                }
            }
        }
        return ans;
    }
};