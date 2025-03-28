// LeetCode 2716 最小化字符串长度

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minimizedStringLength(string s) {
        return set<char>(s.begin(), s.end()).size();
    }
};