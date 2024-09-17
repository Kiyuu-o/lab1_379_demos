#include <sys/times.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    struct tms start_times;
    struct tms cease_times;

    times(&start_times);

    int pid = fork();

    if (pid == 0) {
        printf("This is a child process!\n");

        for (int i = 0; i < 300000; i += 1) {
            printf("Got a number %d\n", i);
        }
        _exit(1);
    }

    waitpid(pid, NULL, 0);
    times(&cease_times);

    printf("  user time: %lf\n", (double) (cease_times.tms_utime - start_times.tms_utime) / sysconf(_SC_CLK_TCK));
    printf("system time: %lf\n", (double) (cease_times.tms_stime - start_times.tms_stime) / sysconf(_SC_CLK_TCK));
    printf("  user time: %lf\n", (double) (cease_times.tms_cutime - start_times.tms_cutime) / sysconf(_SC_CLK_TCK));
    printf("system time: %lf\n", (double) (cease_times.tms_cstime - start_times.tms_cstime) / sysconf(_SC_CLK_TCK));
}
