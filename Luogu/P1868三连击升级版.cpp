/*************************************************************************
	> File Name: P1868三连击升级版.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月07日 星期日 18时50分57秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int a, b, c;
    bool solved = false;
    cin >> a >> b >> c;
    for(int ans = (123 / a + min(123 % a, 1)) * a; ans <= 987 / a * a; ans += a) {
        int exist[10] ={0};
        int ans2 = ans / a * b, ans3 = ans / a * c, total = 0;
        if(ans2 >= 1000 && ans3 >= 1000) continue;
        exist[0] = 1;
        exist[ans % 10] = 1;
        exist[ans / 10 % 10] = 1;
        exist[ans / 100] = 1;
        exist[ans2 % 10] = 1;
        exist[ans2 / 10 % 10] = 1;
        exist[ans2/ 100] = 1;
        exist[ans3 % 10] = 1;
        exist[ans3 / 10 % 10] = 1;
        exist[ans3/ 100] = 1;
        for(int i = 0; i < 10; ++i) total += exist[i];
        if(total == 10) {
            solved = true;
            cout << ans << ' ' << ans2 << ' ' << ans3 << endl;
        }
        else continue;
    }
    if(!solved) cout << "No!!!" << endl;
    return 0;
}
