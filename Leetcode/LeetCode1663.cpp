// LeetCode 1663 具有给定数值的最小字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        int ind = n - 1;
        while (k > 0) {
            int diff = min(25, k);
            s[ind] += diff;
            k -= diff;
            --ind;
        }
        return s;
    }
};