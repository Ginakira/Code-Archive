// LeetCode 1093 大样本统计

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
    vector<double> sampleStats(vector<int>& count) {
        int n = count.size();
        int total_count = accumulate(count.begin(), count.end(), 0);
        double mean = 0.;
        double median = 0.;
        int min_elem = 256;
        int max_elem = 0;
        int mode = 0;

        int median_left = (total_count + 1) / 2;
        int median_right = (total_count + 2) / 2;
        int cur_cnt = 0;
        int max_freq = 0;
        for (int i = 0; i < n; ++i) {
            mean += count[i] * (i * 1. / total_count);

            if (count[i] > max_freq) {
                max_freq = count[i];
                mode = i;
            }

            if (count[i] > 0) {
                if (min_elem == 256) {
                    min_elem = i;
                }
                max_elem = i;
            }

            if (cur_cnt < median_right && cur_cnt + count[i] >= median_right) {
                median += i;
            }

            if (cur_cnt < median_left && cur_cnt + count[i] >= median_left) {
                median += i;
            }

            cur_cnt += count[i];
        }

        median /= 2.0;

        return {(double)min_elem, (double)max_elem, mean, median, (double)mode};
    }
};