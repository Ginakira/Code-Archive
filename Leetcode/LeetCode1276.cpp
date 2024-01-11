// LeetCode 1276 不浪费原料的汉堡制作方案

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
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        // j: jumbo, s: small, t: tomato, c: cheese
        // 4j + 2s = t; j + s = c; 2j + 2s = 2c; 2j = t - 2c;
        if (tomatoSlices & 1 || tomatoSlices < 2 * cheeseSlices ||
            4 * cheeseSlices < tomatoSlices) {
            return {};
        }
        int total_jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
        int total_small = cheeseSlices - total_jumbo;

        return {total_jumbo, total_small};
    }
};
