// LeetCode 2928 给小朋友们分糖果 I

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
    int distributeCandies(int n, int limit) {
        int res = 0;
        int up = min(n, limit);
        for (int i = 0; i <= up; ++i) {
            for (int j = 0; j <= up; ++j) {
                if (i + j > n) {
                    break;
                }
                if (n - i - j <= up) {
                    ++res;
                }
            }
        }
        return res;
    }
};

class Solution2 {
   public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        int up = min(n, limit);
        for (int i = 0; i <= up; ++i) {
            if (n - i > limit * 2) {
                continue;
            }
            res += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return res;
    }
};