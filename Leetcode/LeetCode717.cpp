// LeetCode 717 1比特与2比特字符

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isOneBitCharacter(vector<int>& bits) {
        size_t n = bits.size();
        if (bits[n - 1] == 1) {
            return false;
        }

        size_t ind = 0;
        while (ind < n) {
            if (ind == n - 1) {
                return true;
            }
            if (bits[ind] == 0) {
                ++ind;
            } else {
                ind += 2;
            }
        }
        return false;
    }
};