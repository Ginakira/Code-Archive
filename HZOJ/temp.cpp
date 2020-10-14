/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/13 22:19:36
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char str[50];
    while (scanf("%[^\n]\n", str) != EOF) {
        printf("==============\n");
        for (int i = 0; i < 10; ++i) {
            printf("%d ", (int)str[i]);
        }
        printf("\n==============\n");
    }
    return 0;
}