#include <stdio.h>

#define DEBUG

#ifdef DEBUG
#define log(frm, arg...)                                         \
    {                                                            \
        printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__); \
        printf(frm, ##arg);                                      \
        printf("\n");                                            \
    }
#endif
#define contact(a, b) a##b

int main() {
    int a = 123;
    int abcdef = 15;
    contact(abc, def) = 23;
    log("%d", a);
    log("hello haizei");
    log("%d", abcdef);
    return 0;
}