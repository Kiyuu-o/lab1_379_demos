#include <unistd.h>
#include <stdio.h>

int main(void) {
    fork(); // 2
    fork(); // 4
    fork(); // 8
    printf("hello\n");
}
