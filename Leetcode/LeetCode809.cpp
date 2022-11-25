// LeetCode 809 情感丰富的文字

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    int check(const string &target, const string &s) {
        size_t i = 0, j = 0, tn = target.size(), sn = s.size();
        while (i < tn && j < sn) {
            if (target[i] != s[j]) {
                return 0;
            }
            char ch = target[i];
            int cnt_t = 0, cnt_s = 0;
            while (i < tn && target[i] == ch) {
                ++cnt_t;
                ++i;
            }
            while (j < sn && s[j] == ch) {
                ++cnt_s;
                ++j;
            }
            if (cnt_t < cnt_s) {
                return 0;
            }
            if (cnt_t != cnt_s && cnt_t < 3) {
                return 0;
            }
        }
        return i == tn && j == sn;
    }

   public:
    int expressiveWords(string s, vector<string> &words) {
        int cnt = 0;
        for (auto &word : words) {
            cnt += check(s, word);
        }
        return cnt;
    }
};