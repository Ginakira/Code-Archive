// LeetCode 1781 所有字符串美丽值之和

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int beautySum(string s) {
        size_t n = s.size();
        int sum = 0;
        for (size_t i = 0; i < n; ++i) {
            array<int, 26> cnt{0};
            int max_freq = 0;
            for (size_t j = i; j < n; ++j) {
                ++cnt[s[j] - 'a'];
                max_freq = max(max_freq, cnt[s[j] - 'a']);
                int min_freq = n;
                for (size_t k = 0; k < 26; ++k) {
                    if (cnt[k] <= 0) {
                        continue;
                    }
                    min_freq = min(min_freq, cnt[k]);
                }
                sum += max_freq - min_freq;
            }
        }
        return sum;
    }
};