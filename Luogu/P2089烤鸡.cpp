/*************************************************************************
	> File Name: P2089烤鸡.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月08日 星期一 19时28分23秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, sum = 0, ans = 0;
    cin >> n;
    //输入数据超过30 不存在 输出0结束
    if(n > 30 || n < 10) {
        cout << 0 << endl;
        return 0;
    }
    for(int a = 1; a <= 3; ++a) {
        for(int b = 1; b <= 3; ++b) {
            for(int c = 1; c <= 3; ++c) {
                for(int d = 1; d <= 3; ++d) {
                    for(int e = 1; e <= 3; ++e) {
                        for(int f = 1; f <= 3; ++f) {
                            for(int g = 1; g <= 3; ++g) {
                                for(int h = 1; h <= 3; ++h) {
                                    for(int j = 1; j <= 3; ++j) {
                                        for(int k = 1; k <= 3; ++k) {
                                            sum = a + b + c + d + e + f + g + h + j + k;
                                            if(sum == n) {
                                                ans++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    for(int a = 1; a <= 3; ++a) {
        for(int b = 1; b <= 3; ++b) {
            for(int c = 1; c <= 3; ++c) {
                for(int d = 1; d <= 3; ++d) {
                    for(int e = 1; e <= 3; ++e) {
                        for(int f = 1; f <= 3; ++f) {
                            for(int g = 1; g <= 3; ++g) {
                                for(int h = 1; h <= 3; ++h) {
                                    for(int j = 1; j <= 3; ++j) {
                                        for(int k = 1; k <= 3; ++k) {
                                            sum = a + b + c + d + e + f + g + h + j + k;
                                            if(sum == n) {
                                                cout << a << ' ';
                                                cout << b << ' ';
                                                cout << c << ' ';
                                                cout << d << ' ';
                                                cout << e << ' ';
                                                cout << f << ' ';
                                                cout << g << ' ';
                                                cout << h << ' ';
                                                cout << j << ' ';
                                                cout << k << endl;

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
