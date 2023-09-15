// LCP 50 宝石补给

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
    int giveGem(vector<int> &gem, vector<vector<int>> &operations) {
        for (auto &op : operations) {
            int given = gem[op[0]] / 2;
            gem[op[0]] -= given;
            gem[op[1]] += given;
        }
        return *max_element(gem.begin(), gem.end()) -
               *min_element(gem.begin(), gem.end());
    }
};
