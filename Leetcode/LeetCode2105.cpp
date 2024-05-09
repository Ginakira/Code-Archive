// LeetCode 2105 给植物浇水II

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
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int a_pos = 0, b_pos = n - 1;
        int a_cap = capacityA, b_cap = capacityB;
        int refill_cnt = 0;
        while (a_pos <= b_pos) {
            if (a_pos == b_pos) {
                if (max(a_cap, b_cap) < plants[a_pos]) {
                    ++refill_cnt;
                }
                break;
            }
            if (plants[a_pos] > a_cap) {
                ++refill_cnt;
                a_cap = capacityA;
            }
            if (plants[b_pos] > b_cap) {
                ++refill_cnt;
                b_cap = capacityB;
            }
            a_cap -= plants[a_pos];
            b_cap -= plants[b_pos];
            ++a_pos;
            --b_pos;
        }
        return refill_cnt;
    }
};