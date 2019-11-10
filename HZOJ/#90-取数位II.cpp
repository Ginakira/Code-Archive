#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    cin >> num;
    cout << num / 100 << endl << num % 100 / 10 << endl << num % 10;
    return 0;
}