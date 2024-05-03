// LeetCode 1491 去掉最低工资和最高工资后的工资平均值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <ranges>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    double average(vector<int>& salary) {
        int n = salary.size();
        auto [min_salaray, max_salary] = ranges::minmax(salary);
        int sum =
            accumulate(salary.begin(), salary.end(), -min_salaray - max_salary);
        return 1.0 * sum / (n - 2);
    }
};