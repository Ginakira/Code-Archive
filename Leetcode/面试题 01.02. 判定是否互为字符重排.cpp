// 面试题 01.02. 判定是否互为字符重排

#include <algorithm>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool CheckPermutation(string s1, string s2) {
        return multiset(s1.begin(), s1.end()) == multiset(s2.begin(), s2.end());
    }
};