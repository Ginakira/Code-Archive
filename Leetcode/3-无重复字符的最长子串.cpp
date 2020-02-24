#include <string>
using namespace std;

// 暴力标记法 52ms 9.4MB
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, len = s.length();
        for (int i = 0; i < len; ++i) {
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