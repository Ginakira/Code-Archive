// LeetCode 12 整数转罗马数字
#include <string>
#include <vector>
using namespace std;

// Solution1: 模拟
const pair<int, string> symbols[] = {
    {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
    {5, "V"},    {4, "IV"},   {1, "I"},
};

class Solution {
   public:
    string intToRoman(int num) {
        string roman;
        for (auto &[value, symbol] : symbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};

// Solution2: 各位硬编码
const string thousands[] = {"", "M", "MM", "MMM"};
const string hundreds[] = {"",  "C",  "CC",  "CCC",  "CD",
                           "D", "DC", "DCC", "DCCC", "CM"};
const string tens[] = {"",  "X",  "XX",  "XXX",  "XL",
                       "L", "LX", "LXX", "LXXX", "XC"};
const string ones[] = {"",  "I",  "II",  "III",  "IV",
                       "V", "VI", "VII", "VIII", "IX"};

class Solution2 {
   public:
    string intToRoman(int num) {
        return thousands[num / 1000] + hundreds[num % 1000 / 100] +
               tens[num % 100 / 10] + ones[num % 10];
    }
};