// LeetCode 1791 找出星型图的中心节点

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        return (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
                   ? edges[0][0]
                   : edges[0][1];
    }
};