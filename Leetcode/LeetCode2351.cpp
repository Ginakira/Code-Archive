// LeetCode 2351 第一个出现两次的字母

#include <algorithm>
#include <bitset>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    char repeatedCharacter(string s) {
        bitset<26> bs;
        for (char c : s) {
            if (bs[c - 'a']) {
                return c;
            }
            bs.set(c - 'a');
        }
        return -1;
    }
};