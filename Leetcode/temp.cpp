/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/06/11 17:27:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T = int>
class Foo {
   public:
    vector<T> data;
};

int main() { 
    Foo f;
    Foo<string> f2;
    return 0; }