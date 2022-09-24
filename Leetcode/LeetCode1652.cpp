// LeetCOde 1652 拆炸弹

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n);
        if (k == 0) {
            return res;
        }
        int l = k > 0 ? 1 : n + k;
        int r = k > 0 ? k : n - 1;
        int sum = 0;
        for (int i = l; i <= r; ++i) {
            sum += code[i];
        }
        for (int i = 0; i < n; ++i) {
            res[i] = sum;
            sum -= code[l];
            sum += code[(r + 1) % n];
            l = (l + 1) % n;
            r = (r + 1) % n;
        }
        return res;
    }
};