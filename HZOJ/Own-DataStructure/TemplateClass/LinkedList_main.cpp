/************************************************************
    File Name : LinkedList_main.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-15 10:16:05
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

LinkedList<char> l;

int main() {
    srand(time(0));
    int index, op, max_op = 20;
    char val;
    for (int i = 0; i < max_op; ++i) {
        val = 'A' + rand() % 26;
        index = rand() % (l.get_len() + 3);
        op = rand() % 5;
        switch (op) {
            case 0:
            case 4:
            case 1: {
                l.insert(index, val);
                l.output();
            } break;
            case 2: {
                l.delete_node(index);
                l.output();
            } break;
            case 3: {
                l.reverse();
                l.output();
            } break;
        }
    }
    return 0;
}