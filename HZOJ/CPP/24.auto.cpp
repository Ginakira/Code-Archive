/**；**********************************************************
    File Name : 23.auto.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/02 18:40:55
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
    auto a = 123;
    cout << sizeof(a) << endl;
    map<int, int> arr;
    arr[71234324] = 23455;
    arr[3245] = 712;
    arr[123455] = 234;
    // for (map<int, int>::iterator iter = arr.begin(); iter != arr.end();
    // ++iter) {
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        cout << iter->first << ' ' << iter->second << endl;
    }
    // C++11
    for (auto x : arr) {
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}