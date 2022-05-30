#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;
	int i;
	
	if ( (pid = fork()) == 0 ) {
		printf("I'm child : %d\n", getpid());
		for (i=0; i<4; i++){
			printf("child cnt : %d\n", i);
			sleep(1);
		}
	} else if (pid > 0) {
		
		pid = wait(&status);
		
		printf("I'm parent : %d\n", getpid());
		for (i=0; i<4; i++) {
			printf("parent cnt : %d\n", i);
			sleep(1);
		}
	} else {
		perror("fork()");
	}
	return 0;
}