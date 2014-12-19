#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define _POSIX_SOURCE
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main(int argc, const char * argv[]) {
  pid_t pid = 0;
  pid_t pid1 = fork();
  if(pid1 > 0){
    printf("I am the Mother\n");
    pid1 = fork();
  }else{
    printf("I am a child\n");
    for(int i = 0; i<10;i++){
      sleep(1);
      printf("still alive");
    }
  }

  if (pid1 == 0)
    kill(pid,  SIGKILL);
  return 0;
}
