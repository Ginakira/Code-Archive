#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

//计数数组 分别代表B u l b a s r
//一组个数满足1 2 1 1 2 1 1
int cnt[10];

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == 'B') cnt[0]++;
        else if(s[i] == 'u') cnt[1]++;
        else if(s[i] == 'l') cnt[2]++;
        else if(s[i] == 'b') cnt[3]++;
        else if(s[i] == 'a') cnt[4]++;
        else if(s[i] == 's') cnt[5]++;
        else if(s[i] == 'r') cnt[6]++;
    }
    int mod[7] = {1, 2, 1, 1, 2, 1, 1};
    for(int i = 0; i < 7; ++i) {
        cnt[i] /= mod[i];
    }
    sort(cnt, cnt + 7);
    cout << cnt[0];
    return 0;
}