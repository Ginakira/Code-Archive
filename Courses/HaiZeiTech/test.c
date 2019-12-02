/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: 日 12/ 1 15:53:38 2019
 ************************************************************************/

#include<stdio.h>

int main() {
    int a, b, c, d;
    char ipv[233];
    scanf("%d%d%d%d", &a, &b, &c, &d);
    sprintf(ipv, "%d.%d.%d.%d", a, b, c, d);
    printf("%s", ipv);
    FILE *fd = fopen("out", "wb");
    fprintf(fd, "%s", ipv);
    return 0;
}
