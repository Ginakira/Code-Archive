// LeetCode 1816 截断句子

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
   public:
    string truncateSentence(string s, int k) {
        stringstream ss(s);
        string ret, str;
        for (int _ = 0; _ < k; ++_) {
            ss >> str;
            ret.append(" " + str);
        }
        return ret.substr(1);
    }
};