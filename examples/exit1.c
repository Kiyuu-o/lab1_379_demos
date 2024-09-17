#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("start of program\n");
    _exit(3);
    printf("End of program\n");
}
