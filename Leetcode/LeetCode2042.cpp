// LeetCode 2042 检查句子中的数字是否递增

#include <algorithm>
#include <numeric>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool areNumbersAscending(string s) {
        int pre_num = 0;
        stringstream ss(s);
        string token;
        while (ss >> token) {
            try {
                int num = std::stoi(token);
                if (num <= pre_num) {
                    return false;
                }
                pre_num = num;
            } catch (std::invalid_argument) {
            }
        }
        return true;
    }
};