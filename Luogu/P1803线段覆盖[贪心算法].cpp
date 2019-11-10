#include <bits/stdc++.h>
using namespace std;
struct match {
    int start;
    int end;
};

inline int read() {
    int x = 0, sign = 1;
    char c = getchar();
    while (c > '9' || c < '0') {
        if (c == '-') sign = -1;
        c = getchar();
    }
    while (c < '9' && c > '0') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * sign;
}

int compare(match a, match b) {
    return a.end < b.end;
}

int main() {
    int n, ans = 1;
    cin >> n;
    match m[n];
    for (int i = 0; i < n; ++i) {
        m[i].start = read();
        m[i].end = read();
    }
    sort(m, m + n, compare);
    int end = m[0].end;
    for (int i = 1; i < n; ++i) {
        if (end <= m[i].start) {
            ans++;
            end = m[i].end;
        }
    }
    cout << ans << endl;
    return 0;
}
