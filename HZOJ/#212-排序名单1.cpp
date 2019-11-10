#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string stu[10];
    for (int i = 0; i < 10; ++i) {
        cin >> stu[i];
    }
    sort(stu, stu + 10);
    for (int i = 0; i < 10; ++i) {
        cout << stu[i] << endl;
    }
    return 0;
}