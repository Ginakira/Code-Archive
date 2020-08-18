/************************************************************
    File Name : 37.sort.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/17 14:32:02
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool cmp(int a, int b) { return a > b; }

struct CMP {
    bool operator()(int a, int b) { return a > b; }
};

namespace haizei {
template <typename T>
class less {
   public:
    bool operator()(const T &a, const T &b) { return a < b; }
};

template <typename T>
class greater {
   public:
    bool operator()(const T &a, const T &b) { return a > b; }
};
}  // namespace haizei

int main() {
    srand(time(0));
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = rand() % 100;
    }

    // sort(arr, arr + 10, [](int a, int b) { return a > b; });
    // sort(arr, arr + 10, CMP());
    sort(arr, arr + 10, haizei::greater<int>());
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    sort(arr, arr + 10, haizei::less<int>());
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}