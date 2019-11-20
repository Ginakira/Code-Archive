/************************************************************
    File Name : 树复习-建立顺序存储完全二叉树.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-20 20:01:19
************************************************************/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tree[10000];

void output(int index) {
    printf("%c", tree[index]);
    if (tree[index * 2 + 1] != '#') {
        printf("(");
        output(index * 2 + 1);
    }
    if (tree[index * 2 + 2] != '#') {
        printf(",");
        output(index * 2 + 2);
    }
    if (tree[index * 2 + 1] != '#' || tree[index * 2 + 2] != '#') {
        printf(")");
    }
}

int main() {
    char ch;
    memset(tree, '#', sizeof(tree));
    int ind = 0;
    while (scanf("%c", &ch)) {
        if (ch == '$')
            break;
        else if (ch != ' ')
            tree[ind++] = ch;
    }
    if (ind > 0) output(0);
    return 0;
}