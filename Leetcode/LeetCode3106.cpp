// LeetCode 3106 满足距离约束且字典序最小的字符串

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
    string getSmallestString(string s, int k) {
        auto cal_dis = [](char base, char diff) {
            return min(diff + 26 - base, abs(diff - base));
        };
        int remain = k;
        for (int i = 0; i < s.size() && remain > 0; ++i) {
            char &ch = s[i];
            for (char c = 'a'; c < ch; ++c) {
                int dis = cal_dis(ch, c);
                if (dis <= remain) {
                    ch = c;
                    remain -= dis;
                    break;
                }
            }
        }
        return s;
    }
};

class Solution2 {
   public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            int dis = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dis <= k) {
                s[i] = 'a';
                k -= dis;
            } else {
                s[i] -= k;
                break;
            }
        }
        return s;
    }
};