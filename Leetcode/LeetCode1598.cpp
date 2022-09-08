// LeetCode 1598 文件夹操作日志搜集器

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for (auto& log : logs) {
            if (log == "./") {
                continue;
            } else if (log == "../") {
                if (cnt > 0) {
                    --cnt;
                }
            } else {
                ++cnt;
            }
        }
        return cnt;
    }
};