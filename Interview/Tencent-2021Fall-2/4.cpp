// 30%
#include <algorithm>
#include <iostream>
#include <list>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    list<int> nums = {n};
    bool loop = true;
    while (loop) {
        loop = false;
        for (auto it = nums.begin(); it != nums.end();) {
            int num = *it;
            if (num > 1) {
                loop = true;
                it = nums.erase(it);
                nums.insert(it, {num / 2, num % 2, num / 2});
            } else {
                ++it;
            }
        }
    }
    int count = 0, i = 0;
    for (int num : nums) {
        ++i;
        if (i < l) continue;
        count += num;
        if (i == r) break;
    }
    cout << count << endl;
    return 0;
}