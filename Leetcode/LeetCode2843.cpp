// LeetCOde 2843 统计对称整数的数目

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
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int num = low; num <= high; ++num) {
            if (num >= 10 && num < 100) {
                cnt += (num % 11 == 0);
            } else if (num >= 1000 && num < 10000) {
                cnt += ((num / 1000 + num % 1000 / 100) ==
                        (num % 100 / 10 + num % 10));
            }
        }
        return cnt;
    }
};