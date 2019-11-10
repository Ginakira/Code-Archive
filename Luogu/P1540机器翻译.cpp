/*************************************************************************
	> File Name: P1540机器翻译.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月13日 星期六 21时26分52秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

bool inmem[1000];
int main() {
    int m, n, ans = 0;
    queue<int> mem;
    cin >> m >> n;
    for(int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if(inmem[c]) continue;
        else {
            if(mem.size() >= m) {
                inmem[mem.front()] = false;
                mem.pop();
            }
            mem.push(c);
            ans++;
            inmem[c] = true;
        }
    }
    cout << ans << endl;
    return 0;
}
