// LeetCode 1653 使字符串平衡的最小删除次数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimumDeletions(string s) {
        int f = 0, cnt_b = 0;
        for (char ch : s) {
            if (ch == 'a') {
                f = min(cnt_b, f + 1);
            } else if (ch == 'b') {
                ++cnt_b;
            }
        }
        return f;
    }
};