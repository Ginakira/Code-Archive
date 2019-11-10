/*************************************************************************
	> File Name: P1598垂直柱状图.cpp
	> Author: 坂田银串
	> Mail: ginakira@foxmail.com
	> Created Time: 2019年04月01日 星期一 22时35分18秒
 ************************************************************************/

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main() {
    int count[26] = {0};
    char a[101];
    for(int i = 0; i < 4; ++i) {
        cin.getline(a, 101);
        for(int j = 0; a[j] != '\0'; ++j) {
            if(a[j] <= 'Z' && a[j] >= 'A')
                count[a[j] - 'A']++;
        }
    }
    //计算统计的结果中出现最多字母
    int max = 0;
    for(int i = 0; i < 26; ++i) {
        if(count[i] > max) {
            max = count[i];
        }
    }
    //输出部分
    for(int i = max; i > 0; --i) {
        for(int j = 0; j < 26; ++j) {
            if(count[j] >= i) cout << "* ";
            else cout << "  ";
         }
        cout << endl;
    }
    for(int i = 0; i < 26; ++i) cout << char ('A' + i) << ' ';
    cout << endl;
    return 0;
}
