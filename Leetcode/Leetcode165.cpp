// 比较版本号

#include <iostream>
using namespace std;

class Solution {
   public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while (version1[i] || version2[j]) {
            int val1 = 0;
            int val2 = 0;
            while (version1[i] && version1[i] <= '9' && version1[i] >= '0') {
                val1 = val1 * 10 + version1[i] - '0';
                i++;
            }
            while (version2[j] && version2[j] <= '9' && version2[j] >= '0') {
                val2 = val2 * 10 + version2[j] - '0';
                j++;
            }
            if (val1 - val2) return val1 > val2 ? 1 : -1;
            if (version1[i]) ++i;
            if (version2[j]) ++j;
        }
        return 0;
    }
};

// 优化
class Solution2 {
   public:
    int getNext(string &str, int i, int &val) {  // 返回下一个版本号的位置
        val = 0;
        while (str[i] && str[i] <= '9' && str[i] >= '0') {
            val = val * 10 + str[i] - '0';
            i++;
        }
        if (str[i]) ++i;
        return i;
    }

    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, val1 = 0, val2 = 0;
        while (version1[i] || version2[j]) {
            i = getNext(version1, i, val1);
            j = getNext(version2, j, val2);
            if (val1 - val2) return val1 > val2 ? 1 : -1;
        }
        return 0;
    }
};