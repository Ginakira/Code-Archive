/************************************************************
    File Name : #35-数数字.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-15 11:25:03
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int begin, end;
    cin >> begin >> end;
    if(end - begin <= 0 || end < 0) {
        cout << "ERROR\n";
        return 0;
    }
    if(begin < 0) begin = 0;
    for(int i = begin; i <= end; ++i) {
        cout << i << endl;
    }
    return 0;
}