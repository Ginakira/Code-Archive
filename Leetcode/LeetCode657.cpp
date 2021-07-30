// LeetCode 657 机器人能否返回原点

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 计数
class Solution {
   public:
    bool judgeCircle(string moves) {
        int u_count = count(moves.begin(), moves.end(), 'U');
        int d_count = count(moves.begin(), moves.end(), 'D');
        int l_count = count(moves.begin(), moves.end(), 'L');
        int r_count = count(moves.begin(), moves.end(), 'R');
        return u_count == d_count && l_count == r_count;
    }
};