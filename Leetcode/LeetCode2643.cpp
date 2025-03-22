// LeetCode 2643 一最多的行

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
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max_cnt = 0, max_idx = 0;
        for (int i = 0; i < mat.size(); ++i) {
            int cnt = ranges::count(mat[i], 1);
            if (cnt > max_cnt) {
                max_cnt = cnt;
                max_idx = i;
            }
        }
        return {max_idx, max_cnt};
    }
};