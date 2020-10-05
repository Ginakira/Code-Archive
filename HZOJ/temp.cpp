/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/05 16:36:43
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char str[] = "this-is-a-string-seperate-by-dash";
    printf("%s\n", str);
    char *tok = NULL;
    tok = strtok(str, "-!~=+@");
    do {
        printf("%s\n", tok);
    } while ((tok = strtok(NULL, "-!~=+@")) != NULL);
    return 0;
}