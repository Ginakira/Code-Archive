// LeetCode 1482 制作m束花所需的最少天数
#include <vector>
using namespace std;

// 二分判定
class Solution {
   private:
    bool check(vector<int> &bloomDay, int m, int k, int days) {
        int bouquet = 0;
        int count = 0;
        for (auto &bloom : bloomDay) {
            if (bloom <= days) {
                ++count;
                if (count == k) {
                    ++bouquet;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquet >= m;
    }

   public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        if (m > bloomDay.size() / k) {
            return -1;
        }
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
        int mid;
        while (left < right) {
            mid = (left + right) >> 1;
            if (check(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};