// 实现strStr()
#include <iostream>
using namespace std;

// SUNDAY算法
class Solution {
   public:
    int strStr(string haystack, string needle) {
        int ind[256];
        for (int i = 0; i < 256; ++i) ind[i] = needle.size() + 1;
        for (int i = 0; needle[i]; ++i) {
            ind[(int)needle[i]] = needle.size() - i;
        }
        for (int i = 0, I = haystack.size() - needle.size(); i <= I;) {
            int j = 0;
            for (; needle[j]; ++j) {
                if (haystack[i + j] == needle[j]) continue;
                i += ind[(int)haystack[i + needle.size()]];
                break;
            }
            if (needle[j] == 0) return i;
        }
        return -1;
    }
};

// 双指针朴素匹配
class Solution2 {
   public:
    int strStr(string haystack, string needle) {
        int haystack_len = haystack.size(), needle_len = needle.size();
        if (needle_len == 0) return 0;
        int haystack_p = 0, needle_p = 0;
        while (haystack_p < haystack_len && needle_p < needle_len) {
            if (haystack[haystack_p] != needle[needle_p]) {
                haystack_p -= needle_p - 1;
                needle_p = 0;
                continue;
            }
            ++haystack_p;
            ++needle_p;
        }
        return needle_p == needle_len ? haystack_p - needle_p : -1;
    }
};