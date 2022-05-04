// LeetCode 1823 找出游戏的获胜者

#include <algorithm>
#include <deque>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findTheWinner(int n, int k) {
        deque<int> dq;
        for (int i = 1; i <= n; ++i) {
            dq.push_back(i);
        }
        while (dq.size() > 1) {
            for (int _ = 0; _ < k - 1; ++_) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            dq.pop_front();
        }
        return dq.front();
    }
};