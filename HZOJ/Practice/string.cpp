#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[100];
    while (~scanf("%d", &n)) {
        printf("%s has %d digit\n", str, sprintf(str, "%x", n));
    }
    return 0;
}