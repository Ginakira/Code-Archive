#include <iostream>
#include <algorithm>
using namespace std;

int num[2333];
int flag[2333];
int fin[2333];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> num[i];
    }
    int k = 0;
    for(int i = n; i > 0; --i) {
        if(flag[num[i]] == 0) {
            fin[k++] = num[i];
            flag[num[i]] = 1;
        }
    }
    reverse(fin, fin + k);
    cout << k << endl;
    for(int i = 0; i < k; ++i) {
        cout << fin[i] << ' ';
    }

    return 0;
}