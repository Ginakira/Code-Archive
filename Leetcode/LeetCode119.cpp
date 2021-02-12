// LeetCode 119 杨辉三角 II
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(1, 1);
        while (rowIndex--) {
            for (int i = ans.size() - 1; i >= 1; --i) {
                ans[i] += ans[i - 1];
            }
            ans.emplace_back(1);
        }
        return ans;
    }
};