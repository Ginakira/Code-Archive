// LeetCode 2739 总行驶距离

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
    int distanceTraveled(int mainTank, int additionalTank) {
        int dis = 0;
        while (mainTank >= 5) {
            mainTank -= 5;
            dis += 50;
            if (additionalTank > 0) {
                --additionalTank;
                ++mainTank;
            }
        }
        return dis + mainTank * 10;
    }
};

class Solution2 {
   public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return 10 * (mainTank + min((mainTank - 1) / 4, additionalTank));
    }
};