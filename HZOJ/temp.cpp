/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/10/05 16:43:08
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    char str[] =
        "I love you so much, Ms.Ginger.\nMy love is like a flame burning in my "
        "heart, making it difficult for me to think about anyone but "
        "you.\nPlease accept my love.\n\nWith love,\nMr.Garlic";
    char *tok = NULL;
    tok = strtok(str, "\t\n\r\n \"\',.");
    do {
        printf("%s\n", tok);
    } while ((tok = strtok(NULL, "\t\n\r\n \"\',.")) != NULL);
    return 0;
}