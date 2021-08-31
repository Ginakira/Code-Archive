// 剑指 Offer 40. 最小的k个数
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return {};
        priority_queue<int> pq;
        for (int num : arr) {
            if (pq.size() < k) {
                pq.push(num);
            } else if (num < pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = pq.top();
            pq.pop();
        }
        return result;
    }
};