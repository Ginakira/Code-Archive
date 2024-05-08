// LeetCode 2079 给植物浇水

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
    int wateringPlants(vector<int>& plants, int capacity) {
        int cur_pos = -1;
        int cur_cap = capacity;
        int steps = 0;
        for (auto& plant : plants) {
            if (cur_cap < plant) {
                steps += (cur_pos + 1) * 2;
                cur_cap = capacity;
            }
            cur_cap -= plant;
            ++cur_pos;
            ++steps;
        }
        return steps;
    }
};