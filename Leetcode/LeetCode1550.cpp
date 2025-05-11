// LeetCode 1550 存在连续三个奇数的数组

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
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (int num : arr) {
            if (num & 1) {
                if (++cnt == 3) {
                    return true;
                }
            } else {
                cnt = 0;
            }
        }
        return false;
    }
};