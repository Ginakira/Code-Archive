#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

// AC
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    const int INF = numeric_limits<int>::max();
    int min_ans = INF;
    for (int i = 0; i < n; ++i) {
        int sum = nums[i];
        min_ans = min(sum, min_ans);
        for (int j = i - 1; j >= 0; --j) {
            sum += nums[j];
            min_ans = min(sum, min_ans);
        }
        min_ans = min(sum, min_ans);
    }
    cout << (min_ans == INF ? 0 : min_ans) << endl;
    return 0;
}