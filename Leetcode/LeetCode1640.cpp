// LeetCode 1640 能否连接形成数组

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> mp;
        for (int i = 0; i < pieces.size(); ++i) {
            mp[pieces[i][0]] = i;
        }
        int ind = 0;
        while (ind < arr.size()) {
            if (mp.find(arr[ind]) == mp.end()) {
                return false;
            }
            auto& piece = pieces[mp[arr[ind]]];
            if (arr.size() - ind < piece.size()) {
                return false;
            }
            for (int j = 0; j < piece.size(); ++j, ++ind) {
                if (arr[ind] != piece[j]) {
                    return false;
                }
            }
        }
        return ind == arr.size();
    }
};