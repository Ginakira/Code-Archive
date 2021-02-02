// LeetCode 424 替换后的最长重复字符
#include <string>
#include <vector>
using namespace std;

// 双指针 滑动窗口
class Solution {
   public:
    int characterReplacement(string s, int k) {
        int maxCount = 0, n = s.size();
        vector<int> count(26, 0);
        int left = 0, right = 0, ind;
        while (right < n) {
            ind = s[right] - 'A';
            ++count[ind];
            maxCount = max(maxCount, count[ind]);
            if (right - left + 1 - maxCount > k) {
                --count[s[left] - 'A'];
                ++left;
            }
            ++right;
        }
        return right - left;
    }
};