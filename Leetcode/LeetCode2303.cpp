// LeetCode 2303 计算应缴税款总额

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        size_t n = brackets.size();
        int pre_upper = 0;
        for (size_t i = 0; i < n; ++i) {
            int upper = brackets[i][0], percent = brackets[i][1];
            tax += (min(upper, income) - pre_upper) * 0.01 * percent;
            pre_upper = upper;
            if (income < upper) {
                break;
            }
        }
        return tax;
    }
};