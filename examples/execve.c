#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *args[] = {"fork", NULL};

    execve("fork", args, NULL);

    printf("End of execve\n");
}
