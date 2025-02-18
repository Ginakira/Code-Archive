// LeetCode 2080 区间内查询数字的频率

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

class RangeFreqQuery {
   private:
    unordered_map<int, vector<int>> occur;

   public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            occur[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        const vector<int>& pos = occur[value];
        auto l = ranges::lower_bound(pos, left);
        auto r = ranges::upper_bound(pos, right);
        return distance(l, r);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */