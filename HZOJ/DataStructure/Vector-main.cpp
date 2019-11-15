/************************************************************
    File Name : main.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Created Time: 2019-11-13 星期三 20:35:00
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include "Vector.h"
using namespace std;

Vector v;

int main() {
    srand(time(0));
    int maxop = 20, index, val, op;
    for (int i = 0; i < maxop; ++i) {
        op = rand() % 4;
        index = rand() % (v.len() + 3);
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1: {
                v.insert(index, val);
                v.output();
            } break;
            case 2: {
                v.delete_element(index);
                v.output();
            } break;
            case 3: {
                cout << "Search " << val << " result: " << v.search(val)
                     << endl;
            } break;
        }
    }
    return 0;
}