// LeetCode 2545 根据第K场考试的分数排序

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
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        ranges::sort(score, {}, [k](auto&& v) { return -v[k]; });
        return score;
    }
};