#include <iostream>
using namespace std;

int fib[1010];
int i = 0;

void init() {
    fib[1] = 1, fib[2] = 1;
    for (i = 3; fib[i - 1] <= 1000; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

bool isfib[1010] = {0};
void mark() {
    for (int j = 1; j < i; ++j) {
        isfib[fib[j]] = 1;
    }
}

int main() {
    int n;
    cin >> n;
    init();
    mark();
    for (int j = 1; j <= n; ++j) {
        if(isfib[j])
            cout << 'O';
        else
            cout << 'o';
    }
    return 0;
}