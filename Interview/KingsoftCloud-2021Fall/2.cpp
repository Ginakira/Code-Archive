#include <algorithm>
#include <iostream>
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

    int max_ans = 0;
    for (int i = 0; i < n; ++i) {
        int a = nums[i];
        for (int j = i + 1; j < n; ++j) {
            int b = nums[j];
            if (b <= a) continue;
            for (int k = j + 1; k < n; ++k) {
                int c = nums[k];
                if (c <= b) continue;
                max_ans = max(max_ans, a + b + c);
            }
        }
    }
    cout << max_ans << endl;
    return 0;
}