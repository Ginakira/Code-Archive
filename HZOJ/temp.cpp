/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/22 13:14:22
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    stringstream ss;
    string input;
    getline(cin, input);
    ss << input;
    int temp;
    while (ss) {
        ss >> temp;
        cout << temp << endl;
    }
    return 0;
}