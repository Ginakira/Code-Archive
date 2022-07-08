// LeetCode 1217 玩筹码

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0, odd = 0;
        for (int pos : position) {
            if (pos % 2) {
                odd++;
            } else {
                even++;
            }
        }
        return min(odd, even);
    }
};
