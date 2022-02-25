// LeetCode 537 复数乘法

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string complexNumberMultiply(string num1, string num2) {
        auto parse_complex = [](const string &num) {
            size_t n = num.size(), i = 0;
            int real = 0, virt = 0;
            int real_flag = 1;
            if (num[i] == '-') {
                real_flag = -1;
                ++i;
            }
            while (i < n && num[i] != '+') {
                real = real * 10 + num[i] - '0';
                ++i;
            }
            ++i;
            int virt_flag = 1;
            if (num[i] == '-') {
                virt_flag = -1;
                ++i;
            }
            while (i < n && num[i] != 'i') {
                virt = virt * 10 + num[i] - '0';
                ++i;
            }
            return tuple<int, int>(real_flag * real, virt_flag * virt);
        };

        int a, b, c, d, fin_real, fin_virt;
        tie(a, b) = parse_complex(num1);
        tie(c, d) = parse_complex(num2);

        fin_real = a * c - b * d;
        fin_virt = a * d + b * c;

        string ans = to_string(fin_real) + "+" + to_string(fin_virt) + "i";
        return ans;
    }
};