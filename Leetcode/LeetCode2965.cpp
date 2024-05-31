// LeetCode 2965 找出缺失和重复的数字

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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> mark;
        int a_xor_b = 0;
        int a = 0;
        for (int i = 1; i <= n * n; ++i) {
            a_xor_b ^= i;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a == 0) {
                    if (mark.count(grid[i][j])) {
                        a = grid[i][j];
                    } else {
                        mark.emplace(grid[i][j]);
                    }
                }
                a_xor_b ^= grid[i][j];
            }
        }
        return {a, a_xor_b ^ a};
    }
};