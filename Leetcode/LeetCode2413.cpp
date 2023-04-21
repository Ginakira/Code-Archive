// LeetCode 2413 最小偶倍数

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
    int smallestEvenMultiple(int n) { return n & 1 ? 2 * n : n; }
};