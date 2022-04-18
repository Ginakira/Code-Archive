// LeetCode 386 字典序排数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> lexicalOrder(int n) {
        vector<int> result(n);
        int number = 1;
        for (int i = 0; i < n; ++i) {
            result[i] = number;
            if (number * 10 <= n) {
                number *= 10;
            } else {
                while (number % 10 == 9 || number + 1 > n) {
                    number /= 10;
                }
                ++number;
            }
        }
        return result;
    }
};