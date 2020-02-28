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