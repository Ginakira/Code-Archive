// LeetCode 1802 有界数组中指定下标处的最大值

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum, mid;
        while (left < right) {
            mid = (left + right + 1) / 2;
            if (valid(mid, n, index, maxSum)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

   private:
    bool valid(int index_num, int n, int index, int max_sum) {
        int left_part_len = index;
        int right_part_len = n - index - 1;
        return index_num + cal(index_num, left_part_len) +
                   cal(index_num, right_part_len) <=
               max_sum;
    }

    long cal(int num, int len) {
        if (len + 1 < num) {
            return (long)(num - 1 + num - len) * len / 2;
        } else {
            return (long)num * (num - 1) / 2 + len - num + 1;
        }
    }
};