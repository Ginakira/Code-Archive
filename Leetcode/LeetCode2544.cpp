// LeetCode 2544 交替数字和

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
    int alternateDigitSum(int n) {
        int digits = static_cast<int>(std::log10(n)) + 1;
        int sign = digits & 1 ? 1 : -1;
        int ans = 0;
        while (n) {
            ans += sign * n % 10;
            n /= 10;
            sign = -sign;
        }
        return ans;
    }
};