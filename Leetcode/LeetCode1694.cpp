// LeetCode 1694 重新格式化电话号码

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string reformatNumber(string number) {
        string nums;
        nums.reserve(number.size());
        for (auto &c : number) {
            if (isdigit(c)) {
                nums.push_back(c);
            }
        }
        string result;
        int ind = 0, remain = nums.size();
        while (remain > 0) {
            if (remain > 4) {
                result += nums.substr(ind, 3);
                ind += 3;
                remain -= 3;
            } else {
                if (remain == 4) {
                    result +=
                        nums.substr(ind, 2) + '-' + nums.substr(ind + 2, 2);
                } else {
                    result += nums.substr(ind);
                }
                remain = 0;
            }
            result.push_back('-');
        }
        result.pop_back();
        return result;
    }
};