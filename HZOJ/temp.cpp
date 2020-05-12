#include <stdio.h>
#include <string.h>
#define max_n 50

int main() {
    char s[max_n + 5] = {0};
    int l = 0;
    scanf("%s", s);
    for (int i = strlen(s); i > 0; --i) {
        if (s[i] == ' ') break;
        l++;
    }
    printf("%d\n", l);
    return 0;
}