// LeetCode 735 行星碰撞

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int asteroid : asteroids) {
            ans.emplace_back(asteroid);
            while (ans.size() >= 2 &&
                   (ans[ans.size() - 2] > 0 && ans.back() < 0)) {
                int ppre = ans[ans.size() - 2], pre = ans.back();
                ans.pop_back();
                if (abs(ppre) > abs(asteroid)) {
                    break;
                } else if (abs(ppre) < abs(asteroid)) {
                    ans.back() = asteroid;
                } else {
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};