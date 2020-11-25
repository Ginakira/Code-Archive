/************************************************************
    File Name : poj4143.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/11/25 10:45:21
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX_N 100000
int n, m, nums[MAX_N + 5];

void binary_search(int target) {
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    if (left != right && nums[left] + nums[right] == target) {
        cout << nums[left] << ' ' << nums[right] << endl;
    } else {
        cout << "No" << endl;
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    cin >> m;
    binary_search(m);
    return 0;
}