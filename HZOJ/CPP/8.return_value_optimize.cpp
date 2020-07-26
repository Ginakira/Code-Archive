/************************************************************
    File Name : 8.return_value_optimize.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/26 21:11:27
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class People {
   public:
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }

   private:
    string name;
};

People func() {
    People temp_a("sakata");
    return temp_a;
}

int main() {
    People a = func();
    return 0;
}