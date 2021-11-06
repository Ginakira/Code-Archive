/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/11/01 00:20:10
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    cout << vec.capacity() << endl;
    vec.reserve(100);
    cout << vec.capacity() << endl;
    vec.reserve(5);
    cout << vec.capacity() << endl;
    // vector<int>(vec).swap(vec);
    vec.shrink_to_fit();
    cout << vec.capacity() << endl;
    return 0;
}