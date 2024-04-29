// LeetCode 2798 满足目标工作时长的员工数目

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
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return ranges::count_if(hours, [target](int h) { return h >= target; });
    }
};