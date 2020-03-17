// 每日一题 拼写单词
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        int mark[26] = {0};
        for (char c : chars) mark[c - 'a']++;
        int ans = 0;
        for (string s : words) {
            int tmp_mark[26] = {0}, tmp_cnt = s.length();
            for (char c : s) tmp_mark[c - 'a']++;
            for (int i = 0; i < 26; ++i) {
                if (tmp_mark[i] > mark[i]) {
                    tmp_cnt = 0;
                    break;
                }
            }
            ans += tmp_cnt;
        }
        return ans;
    }
};