// LeetCode 888 公平的糖果棒交换
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sum_a = accumulate(A.begin(), A.end(), 0);
        int sum_b = accumulate(B.begin(), B.end(), 0);
        int diff = (sum_a - sum_b) / 2;
        // sa - x + y = sb + x - y
        // x - y == diff --> x = y + diff
        unordered_set<int> us(A.begin(), A.end());
        vector<int> ans;
        for (const int& y : B) {
            int x = y + diff;
            if (us.count(x)) {
                ans = vector<int>{x, y};
                break;
            }
        }
        return ans;
    }
};