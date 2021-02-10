// LeetCode 567 字符串的排列
#include <string>
#include <vector>
using namespace std;

// 通过对比两个记录次数的哈希表是否一致判定窗口内串是否是s1的排列
class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int n = s2.size(), window_size = s1.size();
        vector<int> freq(26, 0), count(26, 0);
        for (int i = 0; i < window_size; ++i) {
            freq[s1[i] - 'a']++;
            count[s2[i] - 'a']++;
        }
        for (int i = window_size; i < n; ++i) {
            if (count == freq) {
                return true;
            }
            ++count[s2[i] - 'a'];
            --count[s2[i - window_size] - 'a'];
        }
        return count == freq;
    }
};

// 双指针优化
class Solution2 {
   public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size(), wsize = s1.size();
        vector<int> count(26, 0);
        for (char &c : s1) {
            ++count[c - 'a'];
        }
        for (int l = 0, r = 0, diff = wsize; r < n;) {
            if (count[s2[r++] - 'a']-- > 0) --diff;
            if (diff == 0) return true;
            if (r - l == wsize && ++count[s2[l++] - 'a'] > 0) ++diff;
        }
        return false;
    }
};