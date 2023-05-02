// LeetCode 970 强整数

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
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        constexpr int kUpperLimit = 20;
        int value1 = 1;
        for (int i = 0; i <= kUpperLimit; ++i) {
            int value2 = 1;
            for (int j = 0; j <= kUpperLimit; ++j) {
                int value = value1 + value2;
                if (value <= bound) {
                    ans.emplace(value);
                } else {
                    break;
                }
                value2 *= y;
            }
            if (value1 > bound) {
                break;
            }
            value1 *= x;
        }
        return vector<int>(ans.begin(), ans.end());
    }
};