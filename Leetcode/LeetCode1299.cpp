// LeetCode 1299 将每个元素替换为右侧最大元素

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
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max_elem = arr[n - 1];
        vector<int> res(n, -1);
        for (int i = n - 2; i >= 0; --i) {
            res[i] = max_elem;
            max_elem = max(max_elem, arr[i]);
        }
        return res;
    }
};