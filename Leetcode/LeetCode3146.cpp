// LeetCodee 3146 两个字符串的排列差

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
    int findPermutationDifference(string s, string t) {
        int ans = 0;
        std::array<int, 26> pos{0};
        for (int i = 0; i < s.size(); ++i) {
            pos[s[i] - 'a'] = i;
        }
        for (int i = 0; i < t.size(); ++i) {
            ans += abs(i - pos[t[i] - 'a']);
        }
        return ans;
    }
};