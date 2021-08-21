// LeetCode 443 压缩字符串

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cur_ind = 0, count = 1;
        int result_ind = 0;
        while (cur_ind < n) {
            if (cur_ind + 1 == n || chars[cur_ind] != chars[cur_ind + 1]) {
                chars[result_ind] = chars[cur_ind];
                ++result_ind, ++cur_ind;
                if (count > 1) {
                    string count_s = to_string(count);
                    for (char c : count_s) {
                        chars[result_ind] = c;
                        ++result_ind;
                    }
                }
                count = 1;
            } else {
                ++count;
                ++cur_ind;
            }
        }
        return result_ind;
    }
};