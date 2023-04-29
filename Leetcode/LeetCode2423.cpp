// LeetCode 2423 删除字符使频率相同

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
    bool equalFrequency(string word) {
        std::array<int, 26> freq{{0}};
        for (auto c : word) {
            ++freq[c - 'a'];
        }
        unordered_map<int, int> freq_cnt;
        for (int f : freq) {
            if (f > 0) {
                ++freq_cnt[f];
            }
        }
        for (int f : freq) {
            if (f == 0) {
                continue;
            }
            --freq_cnt[f];
            if (freq_cnt[f] == 0) {
                freq_cnt.erase(f);
            }
            if (f - 1 > 0) {
                ++freq_cnt[f - 1];
            }
            if (freq_cnt.size() == 1) {
                return true;
            }
            // Restore
            if (f - 1 > 0) {
                --freq_cnt[f - 1];
                if (freq_cnt[f - 1] == 0) {
                    freq_cnt.erase(f - 1);
                }
            }
            ++freq_cnt[f];
        }
        return false;
    }
};