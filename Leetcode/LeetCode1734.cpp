// LeetCode 1734 解码异或后的排列
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int total = 0, odd = 0;
        for (int i = 1; i <= n + 1; ++i) {
            total ^= i;
        }
        for (int i = 1; i < n; i += 2) {
            odd ^= encoded[i];
        }
        vector<int> perm(n + 1);
        perm[0] = total ^ odd;
        for (int i = 1; i <= n; ++i) {
            perm[i] = encoded[i - 1] ^ perm[i - 1];
        }
        return perm;
    }
};