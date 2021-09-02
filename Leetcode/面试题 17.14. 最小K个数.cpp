// 面试题 17.14. 最小K个数

#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.empty() || k == 0) return {};
        priority_queue<int> q;
        for (int num : arr) {
            if (q.size() < k) {
                q.push(num);
            } else if (q.top() > num) {
                q.pop();
                q.push(num);
            }
        }
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.top());
            q.pop();
        }
        return result;
    }
};