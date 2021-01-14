// LeetCode 482 密钥格式化
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// 模拟
// 先将原密钥转为大写 去除-存储起来
// 然后逆序遍历，每K个增加一个-，最后将结果字符串反转即可
class Solution {
   public:
    string licenseKeyFormatting(string S, int K) {
        vector<char> v;
        for (const char &c : S) {
            if (c == '-') continue;
            v.emplace_back(islower(c) ? c - 32 : c);
        }
        string ans = "";
        for (int i = v.size() - 1, count = 0; i >= 0; --i, ++count) {
            if (count == K) {
                ans.push_back('-');
                count = 0;
            }
            ans.push_back(v[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};