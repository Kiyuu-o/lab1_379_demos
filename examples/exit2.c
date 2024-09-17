#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        if (fork() == 0) {
            printf("Child %d with pid %d\n", i, getpid());
            _exit(0);
        }
    }
    printf("hello\n");
}
