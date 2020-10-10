#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    int n;
    scanf("%d\n", &n);

    int i = 0;
    int j;
    int *len = (int *)calloc(n, sizeof(int));
    char *name = (char *)calloc(n, sizeof(char));
    while (scanf("%[^\n]%*c", name) != EOF) {
        len[i] = strlen(&name[i]);
        i++;
        if (i == n) {
            break;
        }
    }

    for (j = 0; j < n; j++) {
        if (len[j] > len[j + 1]) {
            strcpy(&name[j + 1], &name[j]);
        }
        if (j == n - 2) {
            printf("%c", name[n - 1]);
            break;
        }
    }
    return 0;
}