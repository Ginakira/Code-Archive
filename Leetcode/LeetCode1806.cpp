// LeetCode 1806 还原排列的最少操作步数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int reinitializePermutation(int n) {
        int cnt = 0;
        vector<int> perm(n), target(n);
        iota(perm.begin(), perm.end(), 0);
        iota(target.begin(), target.end(), 0);
        do {
            vector<int> arr(n);
            for (int i = 0; i < n; ++i) {
                if (i & 1) {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                } else {
                    arr[i] = perm[i / 2];
                }
            }
            perm = move(arr);
            ++cnt;
        } while (perm != target);
        return cnt;
    }
};