// 每日一题 最小的k个数
#include <queue>
#include <vector>
using namespace std;

// 维护一个大小为k的大顶堆即可
class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int> q;
        for (int i : arr) {
            q.push(i);
            if (q.size() > k) q.pop();
        }
        while (!q.empty()) ans.push_back(q.top()), q.pop();
        return ans;
    }
};