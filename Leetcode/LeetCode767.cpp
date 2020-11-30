// LeetCode 767 重构字符串
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    typedef pair<char, int> PCI;
    string reorganizeString(string S) {
        int n = S.size();
        unordered_map<char, int> mp;
        // 统计最大次数
        int max_freq = 0;
        for (const char &c : S) {
            ++mp[c];
            max_freq = mp[c] > max_freq ? mp[c] : max_freq;
        }
        // 如果最大出现次数超过了字符串长度的一半，则无法进行重构
        if (max_freq > ceil(n / 2.0)) return "";
        // 按出现次数降序排列
        vector<PCI> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), [](const auto &a, const auto &b) -> bool {
            return a.second > b.second;
        });

        // 轮流放置，先奇位，再偶数位
        string ret(S);
        int ind = 0;
        for (int i = 0; i < v.size(); ++i) {
            while (v[i].second) {
                if (ind >= n) ind = 1;
                ret[ind] = v[i].first;
                --v[i].second;
                ind += 2;
            }
        }
        return ret;
    }
};