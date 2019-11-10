#include <iostream>
#include <algorithm>
using namespace std;

//存储n i e t 各需3 1 3 1
int cnt[4];

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'n') cnt[0]++;
        else if(s[i] == 'i') cnt[1]++;
        else if(s[i] == 'e') cnt[2]++;
        else if(s[i] == 't') cnt[3]++;
    }
    //cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << endl;
    cnt[0] -= 1, cnt[0] /= 2, cnt[2] /= 3;
    sort(cnt, cnt + 4);
    cout << cnt[0];
    return 0;
}