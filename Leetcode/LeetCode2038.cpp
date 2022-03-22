// LeetCode 2038 如果相邻两个颜色均相同则删除当前颜色

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool winnerOfGame(string colors) {
        int freq[2]{0, 0};
        int cnt = 0, pre = 'C';
        for (auto ch : colors) {
            if (ch != pre) {
                cnt = 1;
                pre = ch;
                continue;
            }
            ++cnt;
            if (cnt >= 3) {
                ++freq[ch - 'A'];
            }
        }
        return freq[0] > freq[1];
    }
};