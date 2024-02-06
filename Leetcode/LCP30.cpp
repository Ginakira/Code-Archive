// LCP 30 魔塔游戏

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
    int magicTower(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> q;
        int ans = 0;
        long long hp = 1, delay = 0;
        for (int num : nums) {
            if (num < 0) {
                q.emplace(num);
            }
            hp += num;
            if (hp <= 0) {
                ++ans;
                hp -= q.top();
                delay += q.top();
                q.pop();
            }
        }
        hp += delay;
        return hp <= 0 ? -1 : ans;
    }
};