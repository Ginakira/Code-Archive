/************************************************************
    File Name : 2.map.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/21 20:10:40
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    map<double, string> arr;
    arr[1.2] = "hello";
    arr[4.3] = "world";
    arr[-4.5] = "haizei";
    arr[89.7] = "wor;d";

    double n;
    while (cin >> n) {
        // if (arr[n] != "") {  会增加新节点 使效率降低
        if (arr.find(n) != arr.end()) {
            cout << "found : " << arr[n] << endl;
        } else {
            cout << "not found!" << n << endl;
        }
    }

    // for (map<double, string>::iterator iter = arr.begin(); iter != arr.end();
    // ++iter) {}
    for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
        cout << iter->first << ' ' << iter->second << endl;
    }
    return 0;
}