// LeetCode 318 最大单词长度乘积

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }

        int max_ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    max_ans =
                        max(max_ans, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return max_ans;
    }
};