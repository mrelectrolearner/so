#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#define READ  0
#define WRITE 1
int rdm();
int main(void) {
  pid_t pidC;
  int   fd[2];
  char buffer_read[10];
  char buffer_write[10];
  if (pipe(fd) == -1) {
	perror("Creating pipe");
	exit(EXIT_FAILURE);
  }
  pidC = fork();
  switch(pidC) {

  case 0:
	// The child process will execute wc.
	// Close the pipe write descriptor.
	close(fd[WRITE]);
	// Redirect STDIN to read from the pipe.
	int y;
	read(fd[READ],&y, sizeof(int));
	if(y<500){
	printf("menor que 500\n");
	}else{
	printf("mayor o igual que 500\n");
	}
	close(fd[READ]);
	break;

  case -1:
	perror("fork() failed");
	exit(EXIT_FAILURE);
	break;

  default:
	// The parent process will execute ls.
	// Close the pipe read descriptor.
	close(fd[READ]);
	// Redirect STDOUT to write to the pipe.
    	int x=rdm();
	write(fd[WRITE], &x, sizeof(int));
	close(fd[WRITE]);
	//dup2(fd[WRITE], STDOUT_FILENO);
	// Execute ls -l
	exit(0);
	break;

}
}

int rdm(){
	srand(time(NULL));
	int random_number = rand() % 1000 + 1;
	return random_number;
}
