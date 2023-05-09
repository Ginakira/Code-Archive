// LeetCode 2437 有效时间的数目

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
    int countTime(string time) {
        char h1 = time[0], h2 = time[1], m1 = time[3], m2 = time[4];
        int ans = 1;
        if (m2 == '?') {
            ans *= 10;  // 0-9
        }
        if (m1 == '?') {
            ans *= 6;  // 0-5
        }
        if (h1 == '?' && h2 == '?') {
            ans *= 24;
        } else if (h2 == '?') {
            if (h1 == '2') {
                ans *= 4;  // 2? (0-3)
            } else {
                ans *= 10;
            }
        } else if (h1 == '?') {
            if (h2 >= '4') {
                ans *= 2;
            } else {
                ans *= 3;
            }
        }
        return ans;
    }
};