// LeetCode 2207 字符串中最多数目的子序列

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
    long long maximumSubsequenceCount(string text, string pattern) {
        auto find_subseq = [&pattern](string text) {
            long long cnt = 0;
            long long pat_cnt = 0;
            for (char c : text) {
                if (c == pattern[0]) {
                    ++pat_cnt;
                } else if (c == pattern[1]) {
                    cnt += pat_cnt;
                }
            }
            if (pattern[0] == pattern[1]) {
                cnt = pat_cnt * (pat_cnt - 1) / 2;
            }
            return cnt;
        };
        return max(find_subseq(pattern[0] + text),
                   find_subseq(text + pattern[1]));
    }
};

class Solution2 {
   public:
    long long maximumSubsequenceCount(string text, string pattern) {
        long long res = 0;
        int cnt1 = 0, cnt2 = 0;
        for (char c : text) {
            if (c == pattern[1]) {
                res += cnt1;
                ++cnt2;
            }
            if (c == pattern[0]) {
                ++cnt1;
            }
        }
        return res + max(cnt1, cnt2);
    }
};
