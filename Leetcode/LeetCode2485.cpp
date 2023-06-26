// LeetCode 2485 找出中枢整数

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
    int pivotInteger(int n) {
        // (1 + x) * x = (x + n) * (n - x + 1);
        // x = sqrt((n^2 + n) / 2)
        int num = (n * n + n) / 2;
        int ans = sqrt(num);
        return ans * ans == num ? ans : -1;
    }
};