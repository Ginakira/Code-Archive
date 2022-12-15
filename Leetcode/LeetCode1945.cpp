// LeetCode 1945 字符串转化后的各位数字之和

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
   private:
    int sum_string(const string &s) {
        int sum = 0;
        for (char ch : s) {
            sum += ch - '0';
        }
        return sum;
    }

   public:
    int getLucky(string s, int k) {
        string ss;
        for (char ch : s) {
            ss += std::to_string(ch - 'a' + 1);
        }
        int sum = 0;
        for (int _ = 0; _ < k; ++_) {
            sum = sum_string(ss);
            ss = std::to_string(sum);
        }
        return sum;
    }
};