// LeetCode 1178 猜字谜
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 状态压缩 + 位掩码
class Solution {
   public:
    vector<int> findNumOfValidWords(vector<string>& words,
                                    vector<string>& puzzles) {
        // 记录words中对应二进制值出现了多少次
        unordered_map<int, int> freq;
        for (const string& word : words) {
            // 处理成二进制值
            int mask = 0;
            for (char c : word) {
                mask |= (1 << (c - 'a'));
            }
            if (__builtin_popcount(mask) <= 7) {
                ++freq[mask];
            }
        }

        vector<int> ans;
        // 枚举puzzle后六位的所有排列
        for (const string& puzzle : puzzles) {
            int mask = 0;
            // 因为第一位必须有，所以先不计算到掩码中
            for (int i = 1; i < 7; ++i) {
                mask |= (1 << (puzzle[i] - 'a'));
            }
            int subset = mask, total = 0;
            do {
                // 第一位必须存在 加到临时的掩码中
                int s = subset | (1 << (puzzle[0] - 'a'));
                if (freq.count(s)) {
                    total += freq[s];
                }
                subset = (subset - 1) & mask;
            } while (subset != mask);
            ans.emplace_back(total);
        }

        return ans;
    }
};