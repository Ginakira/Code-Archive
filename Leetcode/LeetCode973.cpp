// 973. 最接近原点的 K 个点
#include <algorithm>
#include <vector>
using namespace std;

// Solution 1 STL
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        nth_element(points.begin(), points.begin() + K, points.end(), [](auto &&a, auto &&b) {
            return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
        });
        points.resize(K);
        return points;
    }
};

