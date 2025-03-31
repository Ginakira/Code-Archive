// LeetCode 2278 字母在字符串中的百分比

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
    int percentageLetter(string s, char letter) {
        return floor(ranges::count(s, letter) * 100 / s.size());
    }
};