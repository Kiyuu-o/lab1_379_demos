#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

int main(void) {
	pid_t pid = fork();
	if (pid > 0) {
		kill(pid, SIGINT);
		system("ps -l");
	}
}
