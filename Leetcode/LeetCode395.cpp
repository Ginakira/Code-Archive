// LeetCode 395 至少有K个重复字符的最长子串
#include <string>
#include <vector>
using namespace std;

// 分治法
// 以区间内出现次数小于k的字符为分割点，求各段的答案，取最大值
class Solution {
   public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (k == 1) {
            return n;
        }
        if (n < k) {
            return 0;
        }
        return dfs(s, 0, n - 1, k);
    }

    int dfs(const string &s, int start, int end, int k) {
        if (end <= start || end - start + 1 < k) {
            return 0;
        }
        vector<int> count(26, 0);
        for (int i = start; i <= end; ++i) {
            ++count[s[i] - 'a'];
        }

        bool need_split = false;
        for (const int &cnt : count) {
            if (cnt > 0 && cnt < k) {
                need_split = true;
                break;
            }
        }
        if (!need_split) {
            return end - start + 1;
        }

        int ret = 0;
        int left = start, right = start;
        while (right <= end) {
            while (left <= end) {
                if (count[s[left] - 'a'] >= k) break;
                ++left;
            }
            right = left + 1;
            while (right <= end) {
                if (count[s[right] - 'a'] < k) break;
                ++right;
            }
            if (right - left > ret) {
                ret = max(ret, dfs(s, left, right - 1, k));
            }
            left = right + 1;
        }
        return ret;
    }
};