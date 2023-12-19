// LeetCode 1901 寻找峰值II

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
   private:
    int IndexOfMax(const vector<int>& a) {
        return max_element(a.begin(), a.end()) - a.begin();
    }

   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int left = 0, right = mat.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            int max_j = IndexOfMax(mat[mid]);
            if (mat[mid][max_j] > mat[mid + 1][max_j]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return {left, IndexOfMax(mat[left])};
    }
};