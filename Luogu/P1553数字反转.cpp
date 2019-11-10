#include <bits/stdc++.h>
using namespace std;

char type(char str[]) {//确定输入的内容类型 x小数f分数b百分数z整数
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '.') return 'x';
        else if (str[i] == '/') return 'f';
        else if (str[i] == '%') return 'b';
    }
    return 'z';
}

void int_rev(char a[]) {//整数的反转
    int len = strlen(a);
    bool flag = true;
    if (a[0] == '0' && a[1] == '\0') {
        cout << '0' << endl;
        return;
    }
    for (int i = len - 1; i >= 0; --i) {
        if (a[i] == '0' && flag) {
            continue;
        }
        else flag = false;
        cout << a[i];
    }
    cout << endl;
}

void flt_rev(char a[]) {//小数的反转
    int len = strlen(a);
    bool flag = true;//0的判断
    int pos = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] == '.') {
            pos = i;    //找出小数点的位置
            break;
        }
    }
    for (int i = pos - 1; i >= 0; --i) {//反转输出小数点前
        if (a[0] == '0' && a[1] == '.') {
            cout << '0';
            break;
        }
        if (a[i] == '0' && flag) {
            continue;
        }
        else flag = false;
        cout << a[i];
    }
    cout << '.';
    bool all0 = true;
    for (int i = len - 1; i > pos; --i) {
        if (a[i] != '0') all0 = false;
    }
    if (all0) cout << '0';//小数位全为0时
    else {//否则筛去小数位最后的0
        long long t = 0;
        for (int i = len - 1; i > pos; --i) {//倒序存入t中
            t += a[i] - '0';
            t *= 10;
        }
        while(t % 10 == 0){//末尾是0则删去
            t /= 10;
        }
        cout << t;
    }
    cout << endl;

}

void frac_rev(char a[]) {//分数的反转 与小数大部分相同
    int len = strlen(a);
    bool flag = true;//0的判断
    int pos = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] == '/') {
            pos = i;    //找出斜杠的位置
            break;
        }
    }
    for (int i = pos - 1; i >= 0; --i) {//反转输出斜杠前
        bool all0 = true;
        for (int i = 0; i < pos; ++i) {
            if (a[i] != '0') all0 = false;
        }
        if (all0) {
            cout << '0';
            break;
        }
        if (a[i] == '0' && flag) {
            continue;
        }
        else flag = false;
        cout << a[i];
    }
    cout << '/';
    flag = true; //0的判断状态初始化
    for (int i = len - 1; i > pos; --i) {//反转输出斜杠后
        if (a[i] == '0' && flag) {
            continue;
        }
        else flag = false;
        cout << a[i];
    }
    cout << endl;
}

void per_rev(char a[]) {//百分数的反转
    int len = strlen(a);
    bool flag = true;//0的判断
    if (a[0] == '0' && a[1] == '%') {
        cout << "0%" << endl;
        return ;
    }
    for (int i = len - 2; i >= 0; --i) {//反转输出百分号前
        if (a[i] == '0' && flag) {
            continue;
        }
        else flag = false;
        cout << a[i];
    }
    cout << '%';
    cout << endl;
}

int main() {
    char c[100];
    cin >> c;
    if (type(c) == 'z') int_rev(c);
    else if (type(c) == 'x') flt_rev(c);
    else if (type(c) == 'f') frac_rev(c);
    else per_rev(c);
    return 0;
}