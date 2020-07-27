/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/27 12:18:45
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Data {
    int a, b;
    bool operator<(const Data &obj) const { return a * b < obj.a * obj.b; }
};

vector<Data> arr;

int main() {
    int n, a, b;
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin() + 1, arr.end());
    int p = arr[0].a, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (p / arr[i].b > ans) {
            ans = p / arr[i].b;
            p *= arr[i].a;
        }
    }
    cout << ans << endl;
    return 0;
}