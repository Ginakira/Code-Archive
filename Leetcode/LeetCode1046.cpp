// LeetCode 1046 最后一块石头的重量
#include <queue>
#include <vector>
using namespace std;

// Solution1: 优先队列
class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;
        for (const int& stone : stones) heap.push(stone);
        while (heap.size() > 1) {
            int x, y;
            y = heap.top(), heap.pop();
            x = heap.top(), heap.pop();
            if (x != y) heap.push(y - x);
        }
        return heap.empty() ? 0 : heap.top();
    }
};

