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
            ind[needle[i]] = needle.size() - i;
        }
        for (int i = 0, I = haystack.size() - needle.size(); i <= I;) {
            int j = 0;
            for (; needle[j]; ++j) {
                if (haystack[i + j] == needle[j]) continue;
                i += ind[haystack[i + needle.size()]];
                break;
            }
            if (needle[j] == 0) return i;
        }
        return -1;
    }
};

// 朴素匹配
class Solution2 {
   public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int pa = 0, pb = 0;
        while (pa < haystack.size() && pb < needle.size()) {
            if (haystack[pa] != needle[pb]) {
                pa -= pb - 1, pb = 0;
                continue;
            }
            ++pa, ++pb;
        }
        return pb == needle.size() ? pa - pb : -1;
    }
};