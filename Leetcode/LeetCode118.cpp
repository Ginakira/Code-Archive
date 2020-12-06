// LeetCode 118 杨辉三角
#include <vector>
using namespace std;

// Solution1 0ms
class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j <= i; ++j) {
                ret[i].push_back(
                    j == 0 || j == i ? 1 : ret[i - 1][j] + ret[i - 1][j - 1]);
            }
        }
        return ret;
    }
};