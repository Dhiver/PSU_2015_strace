#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
  int status = 1407;

  if(WIFEXITED(status)) {
    printf("Exit status %d\n", WEXITSTATUS(status));
  } else if(WIFSIGNALED(status)) {
    printf("Terminated by signal %d (%s)%s\n",
           WTERMSIG(status),
           strsignal(WTERMSIG(status)),
           WCOREDUMP(status)?" (core dumped)":"");
  } else if(WIFSTOPPED(status)) {
    printf("Stopped by signal %d (%s)\n",
           WSTOPSIG(status),
           strsignal(WSTOPSIG(status)));
  } else if(WIFCONTINUED(status)) {
    printf("Continued\n");
  }
}
