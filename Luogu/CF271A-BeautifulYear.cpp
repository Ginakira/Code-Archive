#include <iostream>
#include <cstring>
using namespace std;

bool exs[10] = {0};

bool judge(int y) {
    memset(exs, 0, sizeof(exs));
    while(y != 0) {
        if(exs[y % 10]) return false;
        exs[y % 10] = 1;
        y /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    for(int i = n + 1; i <= 9012; ++i) {
        if(judge(i)) {
            cout << i;
            return 0;
        }
    }
    return 0;
}