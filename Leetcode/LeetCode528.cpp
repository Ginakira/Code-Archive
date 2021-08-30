// LeetCode 528 按权重随机选择

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<int> pre_sum;
    int total_sum;

   public:
    Solution(vector<int>& w) {
        srand(time(0));
        partial_sum(w.begin(), w.end(), back_inserter(pre_sum));
        total_sum = pre_sum.back();
    }

    int pickIndex() {
        int x = rand() % total_sum + 1;
        return lower_bound(pre_sum.begin(), pre_sum.end(), x) - pre_sum.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */