// LeetCode 2652 倍数求和

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
   private:
    int f(int n, int m) {
        // [1,n]可被m整除数之和
        return (m + n / m * m) * (n / m) / 2;
    }

   public:
    int sumOfMultiples(int n) {
        // 容斥原理
        return f(n, 3) + f(n, 5) + f(n, 7) - f(n, 3 * 5) - f(n, 3 * 7) -
               f(n, 5 * 7) + f(n, 3 * 5 * 7);
    }
};