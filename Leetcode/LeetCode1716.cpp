// LeetCode 1716 计算力扣银行的钱

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int totalMoney(int n) {
        int pre_mon = 0, pre = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 7 == 0) {
                pre_mon++;
                sum += pre_mon;
                pre = pre_mon;
            } else {
                sum += pre + 1;
                pre++;
            }
        }
        return sum;
    }
};