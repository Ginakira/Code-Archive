// LeetCode 274 H指数

#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int h = 0, i = n - 1;
        while (i >= 0 && citations[i] > h) {
            ++h;
            --i;
        }
        return h;
    }
};