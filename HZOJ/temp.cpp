/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/20 20:10:56
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;
    char *d1 = (char *)&num;
    char *d2 = (char *)&num + 2;
    char *d3 = (char *)&num + 3;
    char *d4 = (char *)&num + 4;
    *d3 = *d1;
    *d1 = 0;
    printf("%d\n", *d1);
    printf("%d\n", *d2);
    printf("%d\n", *d3);
    printf("%d\n", *d4);
    cout << num;
    return 0;
}