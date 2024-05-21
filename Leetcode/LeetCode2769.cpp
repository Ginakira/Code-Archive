// LeetCode 2769 找出最大的可达成数字

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
    int theMaximumAchievableX(int num, int t) { return num + t * 2; }
};