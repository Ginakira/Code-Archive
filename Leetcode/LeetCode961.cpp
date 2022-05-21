// LeetCOde 961 在长度 2N 的数组中找出重复 N 次的元素

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            if (++mp[num] >= 2) {
                return num;
            }
        }
        return -1;
    }
};