// LeetCodd 1405 最长快乐字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        vector<pair<int, char>> chs{{a, 'a'}, {b, 'b'}, {c, 'c'}};

        while (true) {
            sort(chs.begin(), chs.end(), greater<pair<int, int>>());
            bool has_next = false;
            int n = ans.size();
            for (auto &[count, ch] : chs) {
                if (count == 0) {
                    break;
                }
                if (n >= 2 && ans[n - 1] == ch && ans[n - 2] == ch) {
                    continue;
                }
                has_next = true;
                ans.push_back(ch);
                --count;
                break;
            }
            if (!has_next) {
                break;
            }
        }

        return ans;
    }
};