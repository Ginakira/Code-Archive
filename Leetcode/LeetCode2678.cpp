// LeetCOde 2678 老人的数目

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
    int countSeniors(vector<string>& details) {
        return count_if(details.begin(), details.end(), [](const auto& detail) {
            return stoi(string{detail[11], detail[12]}) > 60;
        });
    }
};