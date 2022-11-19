// LeetCode 1732 找到最高海拔

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0, cur = 0;
        for (int diff : gain) {
            cur += diff;
            highest = max(highest, cur);
        }
        return highest;
    }
};