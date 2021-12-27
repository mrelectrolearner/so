#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
//#include "leercadena.h"

int main(int argc, char *argv[]) {
    //char **vector;
    char *comando=argv[1];
    char *argument=argv[2];
    //int i;
    pid_t rc;
    printf("*:%d, not*:%s",*comando, comando);
    if(argc==1){
        printf("argc: %d, comando: %s, argv:%s \n",argc, comando,*argv);
        printf("Indique el programa que se desea ejecutar \n");
        exit(1);
    }
    rc = fork();
    printf("pid:%d",rc);
    if (rc < 0) {
      //perror("No se pudo crear un proceso\n");
      exit(1);
    } else if (rc == 0) {
      execlp(comando, comando,argument,NULL);
      //perror("Return from execlp() not expected"); exit(EXIT_FAILURE);
    } else {
      wait(NULL);
 }

  return 0;
}
