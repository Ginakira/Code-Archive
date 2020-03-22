#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

#define MAX_N 243

char g[MAX_N + 5][MAX_N + 5] = {{0}};

void draw(int k, int i, int j) {
    if (k == 0) {
        g[i][j] = 'o';
        return;
    }
    draw(k - 1, i, j);
    draw(k - 1, i, j + 2 * (int)pow(3, k - 1));
    draw(k - 1, i + (int)pow(3, k - 1), j + (int)pow(3, k - 1));
    draw(k - 1, i + 2 * (int)pow(3, k - 1), j);
    draw(k - 1, i + 2 * (int)pow(3, k - 1), j + 2 * (int)pow(3, k - 1));
    return;
}

int main() {
    int n;
    cin >> n;
    draw(n, 0, 0);
    int len = (int)pow(3, n);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (g[i][j])
                cout << g[i][j];
            else
                cout << ".";
        }
        cout << endl;
    }
    return 0;
}