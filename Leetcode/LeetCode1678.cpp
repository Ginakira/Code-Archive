// LeetCode 1678 设计Goal解析器

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    string interpret(string command) {
        size_t n = command.size();
        string ans;
        for (size_t i = 0; i < n;) {
            if (command[i] == 'G') {
                ans.push_back('G');
                ++i;
            } else if (command[i] == '(') {
                if (command[i + 1] == 'a') {
                    ans += "al";
                    i += 4;
                } else {
                    ans.push_back('o');
                    i += 2;
                }
            }
        }
        return ans;
    }
};