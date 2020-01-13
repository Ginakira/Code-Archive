/************************************************************
    File Name : string.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2020/01/11 16:21:54
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char str[1000];
    scanf("%[^\n]s", str);
    // int len = strlen(str);
    for (int i = 0; str[i]; ++i) {
        if (str[i] == ' ') str[i] = '\n';
    }
    /*
    int pos = 0;
    while (pos < len) {
        pos += printf("%s\n", str + pos);
    }
    */
    printf("%s", str);
    return 0;
}