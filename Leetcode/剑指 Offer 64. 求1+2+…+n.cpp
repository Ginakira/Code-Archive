// 剑指 Offer 64. 求1+2+…+n

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 递归
class Solution {
   public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};