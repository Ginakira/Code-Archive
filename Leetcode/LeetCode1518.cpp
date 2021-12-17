// LeetCode 1518 换酒问题

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while (numBottles >= numExchange) {
            int temp = numBottles / numExchange;
            ans += temp;
            numBottles -= temp * numExchange;
            numBottles += temp;
        }
        return ans;
    }
};