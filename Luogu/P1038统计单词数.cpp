#include <cstring>
#include <cctype>
#include <cstdio>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
void strlower (char *a) {
    for (int i = 0; a[i]; ++i) {
        if (isupper(a[i])) a[i] = tolower(a[i]);
    }
}

int main() {

    char des[1000001], source[11], *p, *q;
    bool flag = false;
    int ans = 0, ans1 = -1;

    cin.getline(source, 11);
    cin.getline(des, 1000001);

    strlower(des);
    strlower(source);

    int len = strlen(source);

    p = des;
    
    for(; q = strstr(p, source); ) {
        if (q != NULL 
        && (q == des || *(q - 1) == ' ') 
        && (*(q + len) == '\0' || *(q + len) == ' ')) {
            ans ++;
            if (flag == false) {
                flag = true;
                ans1 = q - des;
            }
        }
        p = q + len;
    }

    if (flag == true)
        cout << ans << ' ' << ans1 << endl;
    else
        cout << ans1 << endl;

    return 0;
}
