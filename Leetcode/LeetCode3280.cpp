// LeetCode 3280 将日期转换为二进制表示

#include <algorithm>
#include <array>
#include <bitset>
#include <format>
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
   public:
    string convertDateToBinary(string date) {
        stringstream ss(date);
        stringstream out;
        for (string cur; getline(ss, cur, '-');) {
            cur = std::bitset<16>(stoi(cur)).to_string();
            cur.erase(0, cur.find_first_not_of('0'));
            out << cur << '-';
        }
        string out_str = out.str();
        out_str.pop_back();
        return out_str;
    }
};

class Solution2 {
   public:
    string convertDateToBinary(string date) {
        return std::format("{:b}-{:b}-{:b}", stoi(date.substr(0, 4)),
                           stoi(date.substr(5, 2)), stoi(date.substr(8, 2)));
    }
};