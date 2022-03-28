// LeetCode 693 交替位二进制数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool hasAlternatingBits(int n) {
        int pre = n & 1;
        n >>= 1;
        while (n > 0) {
            if ((n & 1) == pre) {
                return false;
            }
            pre = n & 1;
            n >>= 1;
        }
        return true;
    }
};