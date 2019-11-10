#include <iostream>
#include <algorithm>
using namespace std;

bool vis[30001] = {0};
int num[10002] = {0};
int main() {
    int n, k, t;
    int j = 0;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> t;
        if(!vis[t]) {
            num[j] = t;
            vis[t] = 1;
            j++;
        }
    }
    sort(num, num + j);
    /*
    for(int i = 0; i < j; ++i) {
        cout << num[i] << ' ';
    }
    cout << endl;
    */
    if(num[k - 1] == 0) {
        cout << "NO RESULT" << endl;
        return 0;
    }
    cout << num[k - 1] << endl;
    return 0;
}