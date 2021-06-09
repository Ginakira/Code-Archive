// LeetCode 1046 最后一块石头的重量
#include <queue>
#include <vector>
using namespace std;

// Solution1: 优先队列
class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int stone : stones) {
            q.push(stone);
        }
        while (q.size() > 1) {
            int stone_a = q.top();
            q.pop();
            int stone_b = q.top();
            q.pop();
            if (stone_a != stone_b) {
                q.push(stone_a - stone_b);
            }
        }
        return (q.empty() ? 0 : q.top());
    }
};