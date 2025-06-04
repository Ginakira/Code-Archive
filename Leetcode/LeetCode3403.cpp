// LeetCode 3403 从盒子中找出字典序最大的字符串 I
#include <algorithm>
#include <array>
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
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string ans;
        int max_len = n - (numFriends - 1);
        for (int i = 0; i < n; ++i) {
            ans = max(ans, word.substr(i, max_len));
        }
        return ans;
    }
};