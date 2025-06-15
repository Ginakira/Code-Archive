// LeetCode 1432 改变一个整数能得到的最大差值

#include <algorithm>
#include <array>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;


class Solution {
    public:
        int maxDiff(int num) {
            string big = to_string(num);
            string small = big;
    
            if (auto pos = big.find_first_not_of('9'); pos != string::npos) {
                char c = big[pos];
                ranges::replace(big, c, '9');
            }
    
            for (int i = 0; i < small.size(); ++i) {
                char ch = small[i];
                if (ch != '1') {
                    if (i == 0) {
                        ranges::replace(small, ch, '1');
                        break;
                    } else if (ch != '0') {
                        ranges::replace(small, ch, '0');
                        break;
                    }
                }
            }
            return stoi(big) - stoi(small);
        }
    };