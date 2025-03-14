// LeetCode 3110 字符串的分数

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
    int scoreOfString(string s) {
        int score = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            score += abs(s[i] - s[i + 1]);
        }
        return score;
    }
};