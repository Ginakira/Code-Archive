// LeetCOde 875 爱吃香蕉的珂珂

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    bool judge_speed(const vector<int>& piles, int h, int speed) {
        int time_used = 0;
        for (auto pile : piles) {
            time_used += (pile + speed - 1) / speed;
        }
        return time_used <= h;
    }

   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_speed = 1;
        int max_speed = *max_element(piles.begin(), piles.end());
        int ans_speed;
        while (min_speed < max_speed) {
            ans_speed = (min_speed + max_speed) / 2;
            if (judge_speed(piles, h, ans_speed)) {
                max_speed = ans_speed;
            } else {
                min_speed = ans_speed + 1;
            }
        }
        return min_speed;
    }
};