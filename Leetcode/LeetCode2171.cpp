// LeetCode 2171 拿出最少数目的魔法豆

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
    long long minimumRemoval(vector<int>& beans) {
        int n = beans.size();
        long long sum = accumulate(beans.begin(), beans.end(), 0LL);
        long long ans = sum;
        sort(beans.begin(), beans.end());
        for (int i = 0; i < n; ++i) {
            ans = min(ans, sum - 1LL * beans[i] * (n - i));
        }
        return ans;
    }
};