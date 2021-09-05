// LeetCode 470 用Rand7()实现Rand10()

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

// 拒绝采样算法
// https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/xiang-xi-si-lu-ji-you-hua-si-lu-fen-xi-zhu-xing-ji/
class Solution {
   public:
    int rand10() {
        int result;
        while ((result = (rand7() - 1) * 7 + rand7()) > 40)
            ;
        return 1 + result % 10;
    }
};