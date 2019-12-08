#include <cinttypes>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>

#define PUTC(a) putchar(a), ++cnt;

int reverse_num(int num, int *temp) {
    int digit = 0;
    *temp = 0;
    do {
        *temp = *temp * 10 + num % 10;
        num /= 10;
        digit++;
    } while (num);
    return digit;
}

int output_num_with_digit(int num, int digit) {
    int ret = 0;
    while (digit--) {
        putchar(num % 10 + '0');
        num /= 10;
        ret++;
    }
    return ret;
}

int my_printf(const char *frm, ...) {
    int cnt = 0;
    va_list arg;
    va_start(arg, frm);
    for (int i = 0; frm[i]; ++i) {
        switch (frm[i]) {
            case '%': {
                switch (frm[++i]) {
                    case '%': {
                        PUTC(frm[i]);
                    } break;
                    case 'd': {
                        int xx = va_arg(arg, int);
                        uint32_t x;
                        if (xx < 0) {
                            PUTC('-');
                            x = -xx;
                        } else
                            x = xx;
                        int val1 = x / 100000, val2 = x % 100000;
                        int temp1 = 0, temp2 = 0;
                        int digit1 = reverse_num(val1, &temp1);
                        int digit2 = reverse_num(val2, &temp2);
                        if (val1)
                            digit2 = 5;
                        else
                            digit1 = 0;
                        cnt += output_num_with_digit(temp1, digit1);
                        cnt += output_num_with_digit(temp2, digit2);

                    } break;
                    case 's': {
                        const char *str = va_arg(arg, const char *);
                        for (int i = 0; str[i]; ++i) {
                            PUTC(str[i]);
                        }
                    } break;
                }
            } break;
            default: {
                PUTC(frm[i]);
                break;
            }
        }
    }
    return cnt;
}

int main() {
    int a = 123;
    char str[100] = "I love haizei!";
    my_printf("int(a) = %d\n", a);
    my_printf("%s\n", str);
    return 0;
}