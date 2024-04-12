// LeetCode 2923 找到冠军I

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
    int findChampion(vector<vector<int>>& grid) {
        int max_win = 0, max_id = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int sum = accumulate(grid[i].begin(), grid[i].end(), 0);
            if (sum > max_win) {
                max_win = sum;
                max_id = i;
            }
        }
        return max_id;
    }
};