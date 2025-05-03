// LeetCode 1007 行相等的最少多米诺旋转

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
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        auto check = [&](int target) {
            int top_cnt = 0;
            int bottom_cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (tops[i] != target && bottoms[i] == target) {
                    ++top_cnt;
                } else if (tops[i] == target && bottoms[i] != target) {
                    ++bottom_cnt;
                } else if (tops[i] != target && bottoms[i] != target) {
                    return -1;
                }
            }
            return min(top_cnt, bottom_cnt);
        };
        int ans_a = check(tops[0]);
        int ans_b = check(bottoms[0]);
        if (ans_a != -1 && ans_b != -1) {
            return min(ans_a, ans_b);
        }
        return ans_a != -1 ? ans_a : ans_b;
    }
};