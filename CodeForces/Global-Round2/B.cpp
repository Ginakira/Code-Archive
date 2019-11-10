/*************************************************************************
	> File Name: B.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月06日 星期六 20时41分54秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n, h, index, sum = 0;
    int a[1001];
    cin >> n >> h;
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; sum < h; ++i) {
        int s = sum;
        s += a[i];
        if(s <= h) {
            sum = s;
            index = i;
        }
        else break;
        // cout << sum << endl;
    }
    // cout << index << endl;
    sort(a, a + index + 1);
    int temp = 0, ans = index + 1;
    for(int i = 0; i <= index; ++i) temp += a[i];
    if(temp < h) a[index] += h - temp;
    bool insert[index + 1] = {0};
    for(int i = index + 1; i < n; ++i) {
        bool flag = false;
        for(int j = 0; j <= index; ++j) {
            if(a[i] <= a[j] && !insert[j]) {
                a[j] = 0;
                insert[j] = 1;
                ans++;
                flag = true;
                break;
            }
        }
        if(!flag) break;
    }
    // for(int i = 0; i < index; ++i) cout << insert[i] << endl;
    cout << ans << endl;
    return 0;
}
