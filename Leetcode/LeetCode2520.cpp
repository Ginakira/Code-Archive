// LeetCode 2520 统计能整除数字的位数

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int countDigits(int num) {
        int cur = num;
        int cnt = 0;
        while (cur) {
            if (num % (cur % 10) == 0) {
                ++cnt;
            }
            cur /= 10;
        }
        return cnt;
    }
};
