// LeetCode 415 字符串相加
#include <string>
using namespace std;

class Solution {
   public:
    string addStrings(string num1, string num2) {
        if (num1.size() < num2.size()) swap(num1, num2);
        num1 = "0" + num1;
        for (int ind = 1; ind <= num1.size(); ++ind) {
            int p1 = num1.size() - ind, p2 = num2.size() - ind;
            if (p2 >= 0) num1[p1] += num2[p2] - '0';
            if (num1[p1] > '9') {
                num1[p1 - 1]++;
                num1[p1] = (num1[p1] - '0') % 10 + '0';
            }
        }
        if (num1[0] == '0' && num1.size() > 1) num1.erase(0, 1);
        return num1;
    }
};