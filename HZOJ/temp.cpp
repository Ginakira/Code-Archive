#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int pid;
    for (int i = 1; i <= 5; i++) {
        if ((pid = fork()) < 0) perror("fork");
        if (pid == 0) {
            printf("I'm a child\n");
            return 0;
        }
    }
    // wait(NULL);
    for (int i = 0; i < 5; ++i) {
        wait(NULL);
    }
    printf("I'm parent\n");
    return 0;
}