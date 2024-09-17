#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        int f = fork();

        if (f == 0) {
            printf("Child %d with pid %d\n", i, getpid());
            _exit(0);
        }
    }

    while (wait(NULL) > 0);  // This waits until all children are terminated
    // while (waitpid(-1, NULL, 0) > 0);  // Same effect

    printf("parent\n");
    return 0;
}
