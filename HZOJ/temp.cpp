#include <iostream>
using namespace std;

char str[6005];
int n, m, ans[6005], mem[6005];

int main() {
    cin >> n >> m >> &str[1];
    for (int i = 1; i <= n / 2; i++) {  //枚举长度
        int same = 0;
        for (int j = 1, k = i + 1; j <= i; j++, k++) {  //起点为1时
            if (str[j] == str[k]) {
                same++;
            }
        }
        ans[same]++;
        for (int j = 2; j - 1 + i + i <= n; j++) {  //枚举起点
            if (str[j - 1] == str[j - 1 + i]) {  //删掉的那对字符是否相等
                same--;
            }
            if (str[j - 1 + i] == str[j - 1 + i + i]) {  //加入的那对是否相等
                same++;
            }
            ans[same]++;
        }
        mem[i] = same;
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        if (t == 2) {
            cin >> t;
            cout << ans[t] << endl;
            continue;
        }
        char l;
        cin >> l;
        str[++n] = l;
        if (!(n & 1)) {  //加进来如果变成偶数 多计算一轮
            int same = 0, mid = n / 2;
            for (int j = 1, k = 1 + mid; j <= mid; j++, k++) {
                if (str[j] == str[k]) {
                    same++;
                }
            }
            ans[same]++;
            mem[mid] = same;
        }
        for (int j = 1; j <= (n - 1) / 2; j++) {  //加入字符后 在枚举一轮长度
            if (str[n - j - j] == str[n - j]) {
                mem[j]--;
            }
            if (str[n] == str[n - j]) {
                mem[j]++;
            }
            ans[mem[j]]++;
        }
    }

    return 0;
}