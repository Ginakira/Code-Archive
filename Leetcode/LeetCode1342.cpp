// LeetCode 1342 将数字变成0的操作次数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numberOfSteps(int num) {
        int ans = 0;
        while (num != 0) {
            if (num & 1) {
                --num;
            } else {
                num >>= 1;
            }
            ++ans;
        }
        return ans;
    }
};