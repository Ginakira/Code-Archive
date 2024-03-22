// LeetCode 2549 统计桌面上的不同数字

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
    int distinctIntegers(int n) { return n == 1 ? 1 : n - 1; }
};