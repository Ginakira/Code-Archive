// 面试题 01.09. 字符串轮转

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isFlipedString(string s1, string s2) {
        return s2.size() == s1.size() && (s1 + s1).find(s2) != string::npos;
    }
};
