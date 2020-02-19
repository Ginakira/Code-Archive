#include <ctype.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#define MAX_N 1000

int calc(const char *str, int l, int r) {
    int prior = INT32_MAX - 1, temp = 0, pos = -1;
    for (int i = l; i <= r; ++i) {
        int cur_prior = INT32_MAX;
        switch (str[i]) {
            case '(':
                temp += 100;
                break;
            case ')':
                temp -= 100;
                break;
            case '+':
                cur_prior = temp + 1;
                break;
            case '-': {
                cur_prior = temp + 1;
                if (i == 0) break;
                int pre = i - 1;
                while (pre >= 0 && (str[pre] == ' ' || str[pre] == ')')) pre--;
                if (!isdigit(str[pre])) {
                    cur_prior += temp + 50;
                }
            } break;
            case '*':
            case '/':
                cur_prior = temp + 2;
                break;
            case '^':
                cur_prior = temp + 3;
                break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; ++i) {
            if (!isdigit(str[i])) continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    }
    int a = calc(str, l, pos - 1);
    int b = calc(str, pos + 1, r);
    switch (str[pos]) {
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        case '^':
            return (int)pow(a, b);
            break;
    }
    return 0;
}

int main() {
    char str[MAX_N + 5] = {0};
    scanf("%[^\n]s", str);
    printf("%d\n", calc(str, 0, strlen(str) - 1));
    return 0;
}