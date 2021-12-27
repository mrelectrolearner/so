#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
   
    char *comando=argv[1];
    char *argument=argv[2];
    
    pid_t rc;
   
    if(argc==1||argc>3){
        
        printf("Indique el programa que se desea ejecutar \n");
        exit(1);
    }
    rc = fork();
    
    if (rc < 0) {
      
      exit(1);
    } else if (rc == 0) {
      execlp(comando, comando,argument,NULL);
     
    } else {
      wait(NULL);
 }

  return 0;
}
