// 无重复字符的最长子串
#include <map>
#include <set>
#include <string>
using namespace std;

// 暴力标记法 52ms 9.4MB 强转是为了vsc不报警告
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, len = s.length();
        for (int i = 0; i < len && len - i > max_len; ++i) {
            int now_len = 0;
            bool mark[256];
            fill(mark, mark + 256, false);
            for (int j = i; j < len; ++j) {
                if (mark[(int)s[j]]) break;
                now_len++;
                mark[(int)s[j]] = true;
            }
            max_len = max(max_len, now_len);
        }
        return max_len;
    }
};

// 滑动窗口法 42ms
class Solution2 {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, len = s.length();
        set<char> mark;
        int left = 0, right = 0;
        while (left < len && right < len) {
            if (!mark.count(s[right])) {
                mark.insert(s[right++]);
                max_len = max(right - left, max_len);
            } else {
                mark.erase(s[left++]);
            }
        }
        return max_len;
    }
};

// 优化的滑动窗口法 20ms 使用map记录出现位置
// 重复则更新窗口起始点到之前出现位置下一位
class Solution3 {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, len = s.length();
        map<char, int> mp;
        for (int i = 0, j = 0; j < len; ++j) {
            if (mp.count(s[j])) {
                i = max(mp[s[j]] + 1, i);
            }
            max_len = max(max_len, j - i + 1);
            mp[s[j]] = j;
        }
        return max_len;
    }
};

// 使用数组到优化滑动窗口法 4ms
// 因为ASCII码字符集数量级比较小所以可以使用数组代替map 强转是为了vsc不报警告
class Solution4 {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, len = s.length();
        int mark[128] = {0};
        for (int i = 0, j = 0; j < len; ++j) {
            i = max(mark[(int)s[j]], i);
            max_len = max(max_len, j - i + 1);
            mark[(int)s[j]] = j + 1;
        }
        return max_len;
    }
};