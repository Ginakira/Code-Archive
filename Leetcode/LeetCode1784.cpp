// LeetCode 1784 检查二进制字符串字段

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool checkOnesSegment(string s) { return s.find("01") == string::npos; }
};