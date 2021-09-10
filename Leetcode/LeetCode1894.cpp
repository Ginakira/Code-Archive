// LeetCode 1894 找到需要补充粉笔的学生编号

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        if (k >= sum) {
            k %= sum;
        }
        for (int i = 0, n = chalk.size(); i < n; ++i) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};

// 前缀和 + 二分加速
class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        if (chalk[0] > k) {
            return 0;
        }
        for (int i = 1; i < n; ++i) {
            chalk[i] += chalk[i - 1];
            if (chalk[i] > k) {
                return i;
            }
        }
        k %= chalk.back();
        return upper_bound(chalk.begin(), chalk.end(), k) - chalk.begin();
    }
};