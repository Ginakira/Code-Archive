#include <iostream>
using namespace std;

bool map[25][25] = {0};

int main() {
    int n, m, ax, ay;
    cin >> n >> m >> ax >> ay;
    map[ax][ay] = true;
    map[ax - 1][ax - 2] = true;
    
    return 0;
}