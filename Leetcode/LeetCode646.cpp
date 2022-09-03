// LetCode 646 最长数对链

#include <algorithm>
#include <limits>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLongestChain(vector<vector<int>> &pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto &a, auto &b) { return a[1] < b[1]; });
        int cur = numeric_limits<int>::min(), len = 0;
        for (auto &pair : pairs) {
            if (pair[0] > cur) {
                ++len;
                cur = pair[1];
            }
        }
        return len;
    }
};
