#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

struct Target {
    int tar, order, index;
};

Target target[1010010];

int n, num[1010010];
int l = 0, r, mid;

bool cmp1 (Target a, Target b) {
    return a.tar < b.tar;
}

bool cmp2 (Target a, Target b) {
    return a.order < b.order;
}

int binary_search(int tar) {
    r = n - 1;
    while(l <= r) {
        mid = (l + r) / 2;
        if(num[mid] == tar) return mid + 1;
        if(num[mid] < tar) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}

int main() {
    int k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    for (int i = 0; i < k; ++i) {
        cin >> target[i].tar;
        target[i].order = i;
    }
    sort(target, target + k, cmp1);
    for(int i = 0; i < k; ++i) {
        target[i].index = binary_search(target[i].tar);
    }
    sort(target, target + k, cmp2);
    for(int i = 0; i < k; ++i) {
        if(i != 0) cout << ' ';
        cout << target[i].index;
    }

    return 0;
}