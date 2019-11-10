#include <iostream>
#include <cstdio>
using namespace std;
int n, vis[20], out[20];

void print() {
    for(int i = 1; i <= n; ++i) {
        printf("%5d", out[i]);
    }
    cout << endl;
}

void DFS(int k) {
    if(k == n) {
        print();
        return ;
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            vis[i] = 1;
            out[k + 1] = i;
            DFS(k + 1);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    DFS(0);
    return 0;
}