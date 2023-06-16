// LeetCode 2481 分割圆的最少切割次数

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
    int numberOfCuts(int n) { return (n & 1 && n != 1) ? n : n / 2; }
};