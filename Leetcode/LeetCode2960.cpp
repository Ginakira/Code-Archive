// LeetCode 2960 统计已测试设备

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
    int countTestedDevices(vector<int>& batteryPercentages) {
        int need = 0;
        for (auto& per : batteryPercentages) {
            if (per - need > 0) {
                ++need;
            }
        }
        return need;
    }
};