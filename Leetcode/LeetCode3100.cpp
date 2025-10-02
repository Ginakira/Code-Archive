// LeetCode 3100 换水问题 II

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
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0;
        while (numBottles >= numExchange) {
            ans += numExchange;
            numBottles -= numExchange - 1;
            ++numExchange;
        }
        return ans + numBottles;
    }
};