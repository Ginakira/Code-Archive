// 外观数列
#include <string>
using namespace std;

// 8ms
class Solution {
   public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; ++i) {
            string tmp = "";
            int len = ans.length();
            for (int j = 0; j < len; ++j) {
                int cnt = 1;
                while (j + 1 < len && ans[j] == ans[j + 1]) cnt++, j++;
                tmp += to_string(cnt) + ans[j];
            }
            ans = tmp;
        }
        return ans;
    }
};

class Solution2 {
   public:
    string countAndSay(int n) {
        if (n == 1) return string("1");
        string pre_str = countAndSay(n - 1);
        char str[10000];
        int ret = 0, num = pre_str[0], cnt = 1;
        for (int i = 1; pre_str[i]; ++i) {
            if (pre_str[i] == num)
                cnt++;
            else {
                ret += sprintf(str + ret, "%d%c", cnt, num);
                num = pre_str[i];
                cnt = 1;
            }
        }
        ret += sprintf(str + ret, "%d%c", cnt, num);
        return str;
    }
};