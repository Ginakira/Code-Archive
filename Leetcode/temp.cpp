/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/07/16 09:42:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    stringstream ss;
    ss << 1 << " " << 2;
    ss << 3;
    cout << ss.str();
    return 0;
}