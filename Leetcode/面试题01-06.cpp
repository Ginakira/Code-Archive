// 每日一题 字符串压缩
#include <string>
using namespace std;

class Solution {
   public:
    string compressString(string S) {
        int cnt = 1, n = S.length();
        if (!n) return S;
        string zip_s = "";
        char pre = S[0];
        for (int i = 1; i < n; ++i) {
            if (S[i] != pre) {
                zip_s += pre + to_string(cnt);
                pre = S[i], cnt = 1;
                continue;
            }
            cnt++;
        }
        zip_s += pre + to_string(cnt);
        return (zip_s.length() < n) ? zip_s : S;
    }
};