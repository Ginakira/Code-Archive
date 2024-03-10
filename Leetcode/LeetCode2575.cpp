// LeetCode 2575 找出字符串的可整除数组

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
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(), 0);
        long long cur = 0;
        transform(word.begin(), word.end(), ans.begin(), [&cur, m](char ch) {
            cur = (cur * 10 + ch - '0') % m;
            return cur % m == 0;
        });
        return ans;
    }
};