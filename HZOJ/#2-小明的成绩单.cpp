#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int sc;
    cin >> sc;
    if(sc >= 85 && sc <= 100) {
        cout << "A";
    } else if(sc >= 75) {
        cout << "B";
    } else if(sc >= 60) {
        cout << "C";
    } else if(sc >= 0) {
        cout << "D";
    }
    return 0;
}