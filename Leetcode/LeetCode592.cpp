// LeetCode 592 分数加减运算

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    long long read_number(const string &str, size_t &pos) {
        long long ret = 0;
        while (pos < str.size() && isdigit(str[pos])) {
            ret = ret * 10 + str[pos] - '0';
            ++pos;
        }
        return ret;
    }

   public:
    string fractionAddition(string expression) {
        size_t pos = 0, n = expression.size();
        long long cur_nume = 0, cur_deno = 1;
        while (pos < n) {
            int sign = 1;
            if (expression[pos] == '+' || expression[pos] == '-') {
                if (expression[pos] == '-') {
                    sign = -1;
                }
                ++pos;
            }
            long long nume = read_number(expression, pos) * sign;
            ++pos;
            long long deno = read_number(expression, pos);

            cur_nume = nume * cur_deno + cur_nume * deno;
            cur_deno *= deno;
        }
        string res;
        long long div = gcd(cur_nume, cur_deno);
        res += to_string(cur_nume / div) + "/" + to_string(cur_deno / div);
        return res;
    }
};