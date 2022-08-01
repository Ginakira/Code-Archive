// LeetCode 1374 生成每种字符都是奇数个的字符串

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        if (n & 1) {
            return string(n, 'a');
        }
        return string(n - 1, 'a') + "b";
    }
};