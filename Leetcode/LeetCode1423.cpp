// LeetCode 1423 可获得的最大点数
#include <vector>
#include <numeric>
using namespace std;
class Solution {
   public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), window_size = n - k;
        int sum =
            accumulate(cardPoints.begin(), cardPoints.begin() + window_size, 0);
        int min_sum = sum;
        for (int i = window_size; i < n; ++i) {
            sum += cardPoints[i] - cardPoints[i - window_size];
            min_sum = min(min_sum, sum);
        }
        return accumulate(cardPoints.begin(), cardPoints.end(), 0) - min_sum;
    }
};