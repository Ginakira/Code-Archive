// LeetCode 2490 回环句

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
    bool isCircularSentence(string sentence) {
        if (sentence.back() != sentence.front()) {
            return false;
        }
        for (int i = 0; i < sentence.size(); ++i) {
            if (isspace(sentence[i]) && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        return true;
    }
};