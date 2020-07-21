/************************************************************
    File Name : 3.sort.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/21 20:53:28
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b) { return a > b; }  // 返回的是a在什么情况下排在b前

struct CMP_FUNC {
    bool operator()(int a, int b) { return a > b; }
};

int main() {
    int arr[1000], n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    nth_element(arr, arr + 1, arr + n);  // 从小到大排名第二位的元素
    // nth_element只能保证中间指定的那个位置放置的元素是正确的
    cout << arr[1] << endl;

    sort(arr, arr + n, cmp);         // 降序方法1
    sort(arr, arr + n, CMP_FUNC());  // 降序方法2
    sort(arr, arr + n,
         [](int a, int b) -> bool { return a > b; });  // 降序方法3 lambda表达式
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}