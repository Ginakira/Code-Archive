#include <iostream>
using namespace std;

struct Toys {//存储玩具的朝向以及职业名
    int sta;
    string job;
};

struct Operation {//存储每次操作的方向与操作数
    int dire;
    int num;
};

int main() {
    int n, m;
    cin >> n >> m;
    Toys toy[n + 1];
    Operation oper[m + 1];
    //结构体数组升序为逆时针方向，降序为顺时针方向
    for(int i = 0; i < n; ++i) {
        cin >> toy[i].sta >> toy[i].job;
    }

    for(int i = 0; i < m; ++i) {
        cin >> oper[i].dire >> oper[i].num;
    }

    int ans = 0;
    for(int i = 0; i < m; ++i) {
        //cout << "I / Ans:  " << i<< ' ' << ans << endl;
        if(toy[ans].sta == 0) {//如果面朝内
            if(oper[i].dire == 0){//如果往左数
                int temp = ans - oper[i].num;
                if(temp >= 0) {
                    ans = temp;
                    continue;
                } else {
                    ans = n + temp;
                    continue;
                }
            }
            if(oper[i].dire == 1){//如果往右数
                int temp = ans + oper[i].num;
                if(temp < n) {
                    ans = temp;
                    continue;
                } else {
                    ans = temp - n;
                    continue;
                }
            }
        }
        if(toy[ans].sta == 1) {//如果面朝外
            if(oper[i].dire == 1){//如果往右数
                int temp = ans - oper[i].num;
                if(temp >= 0) {
                    ans = temp;
                    continue;
                } else {
                    ans = n + temp;
                    continue;
                }
            }
            if(oper[i].dire == 0){//如果往左数
                int temp = ans + oper[i].num;
                if(temp < n) {
                    ans = temp;
                    continue;
                } else {
                    ans = temp - n;
                    continue;
                }
            }
        }
    }
    //cout << "I / Ans:  " << m << ' ' << ans << endl;
    cout << toy[ans].job << endl;
    return 0;
}