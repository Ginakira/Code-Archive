// LeetCode 2011 执行操作后的变量值

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (auto& op : operations) {
            if (op[1] == '-') {
                --ans;
            } else {
                ++ans;
            }
        }
        return ans;
    }
};