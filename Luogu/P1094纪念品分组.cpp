#include <iostream>
#include <algorithm>
using namespace std;
//Ì°ÐÄ
int pr[30010];
bool vis[30010] = {false};
bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int w, n;
    cin >> w >> n;
    for(int i = 0; i < n; ++i) {
        cin >> pr[i];
    }
    sort(pr, pr + n, cmp);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if(vis[i]) continue;
        for(int j = i + 1; j < n; ++j) {
            if(vis[j]) continue;
            if(pr[i] + pr[j] <= w) {
                ans++;
                vis[i] = true;
                vis[j] = true;
                break;
            }
        }
    }
    /*
    for(int i = 0; i < n; ++i) {
        cout << pr[i] << ' ';
    }
    cout << endl;
    for(int i = 0; i < n; ++i) {
        cout << vis[i] << ' ';
    }
    cout << endl;
    */
    for(int i = 0; i < n; ++i) {
        if(!vis[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}