// LeetCOde 1156 单字符重复子串的最大长度

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxRepOpt1(string text) {
        unordered_map<char, int> count;
        for (auto c : text) {
            ++count[c];
        }

        int ans = 0, n = text.size();
        for (int i = 0; i < n;) {
            // Find current consecutive [i, j)
            int j = i;
            while (j < n && text[j] == text[i]) {
                ++j;
            }
            int cur_cnt = j - i;

            // If the length of segment is less than total count of this
            // character, and there is blank position in the front or behind,
            // then update answer with cur_cnt + 1.
            if (cur_cnt < count[text[i]] && (j < n || i > 0)) {
                ans = max(ans, cur_cnt + 1);
            }

            // Find another segment following this segment with a different
            // character [j + 1, k), if it is not existed then k = j + 1.
            int k = j + 1;
            while (k < n && text[k] == text[i]) {
                ++k;
            }
            ans = max(ans, min(k - i, count[text[i]]));
            i = j;
        }

        return ans;
    }
};