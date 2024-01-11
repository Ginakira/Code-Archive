// LeetCode 274 H指数

#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
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

class Solution2 {
   public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; ++i) {
            int remain = n - i;
            if (citations[i] >= remain) {
                return remain;
            }
        }
        return 0;
    }
};