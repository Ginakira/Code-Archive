// LeetCode 2951 找出峰值

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
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        for (int i = 1; i + 1 < mountain.size(); ++i) {
            if (mountain[i] > mountain[i - 1] &&
                mountain[i] > mountain[i + 1]) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};