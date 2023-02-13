// LeetCOde 1234 替换子串得到平衡字符串

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   private:
    int ind(const char ch) {
        switch (ch) {
            case 'Q':
                return 0;
            case 'W':
                return 1;
            case 'E':
                return 2;
            case 'R':
                return 3;
            default:
                return -1;
        }
    }

   public:
    int balancedString(string s) {
        array<int, 4> cnt{0};
        for (char ch : s) {
            ++cnt[ind(ch)];
        }
        int target_cnt = s.size() / 4;
        int ans = s.size();
        auto check = [&]() {
            return cnt[ind('Q')] <= target_cnt && cnt[ind('W')] <= target_cnt &&
                   cnt[ind('E')] <= target_cnt && cnt[ind('R')] <= target_cnt;
        };

        if (check()) {
            return 0;
        }
        for (int l = 0, r = 0; l < s.size(); ++l) {
            while (r < s.size() && !check()) {
                --cnt[ind(s[r])];
                ++r;
            }
            if (!check()) {
                break;
            }
            ans = min(ans, r - l);
            ++cnt[ind(s[l])];
        }
        return ans;
    }
};