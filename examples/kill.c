#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    int pid = fork();

    if (pid == 0) {
        printf("Child with pid %d\n", getpid());
        while (1) {
            printf("*");
        }
    } else {
        sleep(1);
        kill(pid, SIGKILL);
        printf("\nParent killed pid %d with signal %d\n", pid, SIGKILL);
    }
}
