// LeetCode 2427 公因子的数目

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int commonFactors(int a, int b) {
        int ans = 0;
        int gcd_num = std::gcd(a, b);
        for (int i = 1; i * i <= gcd_num; ++i) {
            if (gcd_num % i == 0) {
                ++ans;
                if (i * i != gcd_num) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};