/*************************************************************************
        > File Name: MAX宏.cpp
        > Author: wangjianduo
        > Mail: 448000069@qq.com
        > Created Time: 2021年01月18日 星期一 22时45分56秒
 ************************************************************************/

#include <cstdio>
#include <iostream>
using namespace std;

#define MAX(a, b)             \
    ({                        \
        __typeof(a) _a = (a); \
        __typeof(b) _b = (b); \
        _a > _b ? _a : _b;    \
    })

#define p(a) \
    { printf("%s = %d\n", #a, a); }

int main() {
    p(MAX(2, 3));
    p(5 + MAX(2, 3));
    p(MAX(2, MAX(3, 4)));
    p(MAX(2, 3 > 4 ? 3 : 4));
    int a = 7;
    p(MAX(a++, 6));
    p(a);
    int k1 = 0, k2 = 0;
    // printf("%d\n", k++);
    // printf("%d\n", (k++));
    int tk1, tk2;
    tk1 = k1++;
    tk2 = (k2++);
    cout << tk1 << endl;
    cout << tk2 << endl;
    return 0;
}
