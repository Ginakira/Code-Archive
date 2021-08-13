/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/07/16 09:42:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

template <typename T, typename L>
void sum(T *vector, L length) {
    const char *type_name = typeid(vector).name();
    if (strcmp(type_name, typeid(float *).name()) == 0) {
        cout << "Float algo" << endl;
    } else if (strcmp(type_name, typeid(double *).name()) == 0) {
        cout << "Double algo" << endl;
    } else {
        cout << "Normal algo" << endl;
    }
}

int main() {
    int *v_int = new int[20];
    float *v_float = new float[20];
    double *v_double = new double[20];
    sum(v_int, 20);
    sum(v_double, 20);
    sum(v_float, 20);
    return 0;
}