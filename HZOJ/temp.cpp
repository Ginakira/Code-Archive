/************************************************************
    File Name : temp.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2021/03/28 22:42:16
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class refClass {
   private:
    double &ref;

   public:
    refClass(double var) : ref(var) {}
};

int main() {
    cout << sizeof(refClass) << endl;
    return 0;
}