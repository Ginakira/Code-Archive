/************************************************************
    File Name : pointer.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019/12/14 20:31:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

#define offset(T, a) (long)(&((T *)(NULL))->a)
#define pchar char *
typedef char *ppchar;

struct Data {
    double a;
    int b;
    char c;
};

void output_main(int argc, char *argv[], char **env) {
    for (int i = 0; i < argc; ++i) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    for (int i = 0; env[i]; ++i) {
        printf("env[%d] = %s\n", i, env[i]);
        if (strncmp(env[i], "USER=", 5) == 0) {
            if (strncmp(env[i] + 5, "sakbta", 6)) {
                printf("EXCUTE NOT PERMITTED!\n");
                exit(0);
            }
        }
    }
    return;
}

int main(int argc, char *argv[], char **env) {
    int num1 = 0x616263;
    int num2 = 0x61626364;
    pchar p1, p2;
    ppchar p3, p4;
    printf("sizeof(p1) = %lu, sizeof(p2) = %lu\n", sizeof(p1), sizeof(p2));
    printf("sizeof(p3) = %lu, sizeof(p4) = %lu\n", sizeof(p3), sizeof(p4));
    printf("%s\n", (char *)(&num1));
    printf("%s\n", (char *)(&num2));
    printf("%s\n", (char *)(&num2 + 1));
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    output_main(argc, argv, env);
    printf("HaiZeiX © 2019\n");
    return 0;
}