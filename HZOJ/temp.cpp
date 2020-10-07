/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/09 19:11:11
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    char str[16] = "hello world!";
    printf("%c\n", *(str + strlen(str) - 4));
    return 0;
}