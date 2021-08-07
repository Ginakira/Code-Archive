// LeetCode 1137 第N个泰波那契数
#include <vector>
using namespace std;

// 记忆化
class Solution {
   public:
    Solution() {
        memory.resize(38, -1);
        memory[0] = 0;
        memory[1] = memory[2] = 1;
    }

    int tribonacci(int n) {
        if (memory[n] != -1) {
            return memory[n];
        }
        return memory[n] =
                   tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    }

   private:
    vector<int> memory;
};

// 滚动数组
class Solution2 {
   public:
    int tribonacci(int n) {
        int nums[3]{0, 1, 1};
        if (n < 3) {
            return nums[n];
        }
        for (int i = 3; i <= n; ++i) {
            int num = nums[0] + nums[1] + nums[2];
            nums[0] = nums[1];
            nums[1] = nums[2];
            nums[2] = num;
        }
        return nums[2];
    }
};