// LeetCode 87 扰乱字符串
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   private:
    // 1 -> True  0 -> Unknown  -1 -> False
    int mem[30][30][31];
    string s1, s2;

    bool checkIfSimilar(int s1_start, int s2_start, int length) {
        unordered_map<char, int> count;
        for (int i = s1_start; i < s1_start + length; ++i) {
            ++count[s1[i]];
        }
        for (int i = s2_start; i < s2_start + length; ++i) {
            --count[s2[i]];
        }
        if (any_of(count.begin(), count.end(),
                   [](const auto &item) { return item.second != 0; })) {
            return false;
        }
        return true;
    }

    bool dfs(int s1_start, int s2_start, int length) {
        // 已经计算过的答案
        if (mem[s1_start][s2_start][length] != 0) {
            return mem[s1_start][s2_start][length] == 1;
        }
        // 两个字符串一致
        if (s1.substr(s1_start, length) == s2.substr(s2_start, length)) {
            mem[s1_start][s2_start][length] = 1;
            return true;
        }
        // 两子串存在字母出现次数不一致的情况
        if (!checkIfSimilar(s1_start, s2_start, length)) {
            mem[s1_start][s2_start][length] = -1;
            return false;
        }
        // 枚举分割点
        for (int i = 1; i < length; ++i) {
            // 分割子串未交换 一一对应
            if (dfs(s1_start, s2_start, i) &&
                dfs(s1_start + i, s2_start + i, length - i)) {
                mem[s1_start][s2_start][length] = 1;
                return true;
            }
            // 发生交换 交叉对应
            if (dfs(s1_start, s2_start + (length - i), i) &&
                dfs(s1_start + i, s2_start, length - i)) {
                mem[s1_start][s2_start][length] = 1;
                return true;
            }
        }
        mem[s1_start][s2_start][length] = -1;
        return false;
    }

   public:
    bool isScramble(string s1, string s2) {
        memset(mem, 0, sizeof(mem));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }
};