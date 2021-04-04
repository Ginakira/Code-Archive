// LeetCode 781 森林中的兔子
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> mp;
        int ret = 0;
        for (const int &answer : answers) {
            ++mp[answer];
        }
        for (auto &[k, v] : mp) {
            ret += ceil((double)v / (k + 1)) * (k + 1);
        }
        return ret;
    }
};