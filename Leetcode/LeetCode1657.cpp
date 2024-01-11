// LeetCode 1657 确定两个字符串是否接近

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
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        if (n != m) {
            return false;
        }
        std::array<int, 26> cnt1{{0}}, cnt2{{0}};
        for (char c : word1) {
            ++cnt1[c - 'a'];
        }
        for (char c : word2) {
            ++cnt2[c - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if ((cnt1[i] == 0 && cnt2[i] != 0) ||
                (cnt1[i] != 0 && cnt2[i] == 0)) {
                return false;
            }
        }
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};
