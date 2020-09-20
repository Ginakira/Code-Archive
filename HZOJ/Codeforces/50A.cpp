/************************************************************
    File Name : 50A.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/09/21 12:36:24
************************************************************/
#include <algorithm>
#include <cerrno>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char str[] = {"Hello world!"};
    sprintf(str, "(%s)", str);
    if (errno != 0) perror("ERRNO:");
    printf("%s\n", str);
    return 0;
}