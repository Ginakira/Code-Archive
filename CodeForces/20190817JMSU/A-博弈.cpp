#include <iostream>
using namespace std;

int main() {
    int n, m;
    while(cin >> n >> m) {
        if (n == 0 || m == 0) break;
        if(n % 2 == 0 || m % 2 == 0) {
            cout << "Wonderful!\n";
        }
        else
            cout << "What a pity!\n";
    }
    return 0;
}