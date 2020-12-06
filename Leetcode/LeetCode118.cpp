// LeetCode 118 杨辉三角
#include <vector>
using namespace std;

// Solution1 4ms
class Solution1 {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            ret.emplace_back();
            for (int j = 0; j < i; ++j) {
                ret[i].push_back(j == 0 ? 1
                                        : ret[i - 1][j] + ret[i - 1][j - 1]);
            }
            ret[i].push_back(1);
        }
        return ret;
    }
};