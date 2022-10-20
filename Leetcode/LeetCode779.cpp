// LeetCOde 779 第K个语法符号

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }
        if (k & 1) {
            return kthGrammar(n - 1, k / 2 + 1);
        }
        return !kthGrammar(n - 1, (k - 1) / 2 + 1);
    }
};