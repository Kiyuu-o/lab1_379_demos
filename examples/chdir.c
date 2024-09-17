#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>

int main(void) {
    char s[PATH_MAX];

    // printing current working directory
    printf("%s\n", getcwd(s, 100));
    // using the command
    chdir("..");
    // printing current working directory after chdir is executed
    printf("%s\n", getcwd(s, 100));
}
