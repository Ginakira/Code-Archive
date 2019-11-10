#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a = 2, b = -1, c = 2;
    if(a < b) {
        if (b < 0) c = 0;
        else
            c += 1;
    }
    printf("%d\n", c);
}