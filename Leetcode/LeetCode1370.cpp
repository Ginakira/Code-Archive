// LeetCode 1370 上升下降字符串
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string sortString(string s) {
        vector<int> cnt(26);
        string ret;
        for (char &c : s) {
            cnt[c - 'a']++;
        }

        while (ret.size() != s.size()) {
            for (int i = 0; i < 26; ++i) {
                if (!cnt[i]) continue;
                ret.push_back(i + 'a');
                cnt[i]--;
            }
            for (int i = 25; i >= 0; --i) {
                if (!cnt[i]) continue;
                ret.push_back(i + 'a');
                cnt[i]--;
            }
        }

        return ret;
    }
};