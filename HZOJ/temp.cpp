/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/31 12:08:39
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> mat = {{1, 1, 0, 0, 0},
                           {1, 1, 1, 1, 0},
                           {1, 0, 0, 0, 0},
                           {1, 1, 0, 0, 0},
                           {1, 1, 1, 1, 1}};

int main() {
    cout << mat[0].size() << endl;
    return 0;
}