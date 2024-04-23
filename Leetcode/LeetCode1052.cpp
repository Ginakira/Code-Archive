// LeetCode 1052 爱生气的书店老板
#include <vector>
using namespace std;

// 滑动窗口
class Solution {
   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int current = 0, max_count = 0;
        for (int i = 0; i < n; ++i) {
            current += (i < X || !grumpy[i]) ? customers[i] : 0;
        }
        max_count = current;
        for (int i = X; i < n; ++i) {
            int left = i - X;
            current -= grumpy[left] ? customers[left] : 0;
            current += grumpy[i] ? customers[i] : 0;
            max_count = max(max_count, current);
        }
        return max_count;
    }
};

class Solution2 {
   public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0;
        int cur = 0;
        int n = customers.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += customers[i] * !(grumpy[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (i >= minutes) {
                int left_ind = i - minutes;
                cur -= customers[left_ind] * grumpy[left_ind];
            }
            cur += customers[i] * grumpy[i];
            ans = max(ans, cur);
        }
        return sum + ans;
    }
};