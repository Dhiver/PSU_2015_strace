/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Thu Mar 31 23:00:10 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/user.h>
#include "strace.h"

int	be_the_child(char **av, char **ae)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (fprintf(stderr, strerror(errno)), 1);
  if (execve(av[0], av, ae) == -1)
    return (fprintf(stderr, strerror(errno)), 1);
  return (0);
}

int				inspect_regs(pid_t pid)
{
  struct user_regs_struct	regs;

  bzero(&regs, sizeof(regs));
  if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
    return (fprintf(stderr, strerror(errno)), 1);
  if (regs.orig_rax && (signed)regs.orig_rax != -1)
    printf("%lld = 0x%llx\n", regs.orig_rax, regs.rax);
  return (0);
}

int	be_the_parent(pid_t pid, int details)
{
  int	status;

  (void)details;
  if (waitpid(pid, &status, 0) == -1)
    return (fprintf(stderr, strerror(errno)), 1);
  while (WIFSTOPPED(status))
    {
      if (inspect_regs(pid))
	return (1);
      if (ptrace(PTRACE_SINGLESTEP, pid, NULL, NULL) == -1)
	return (fprintf(stderr, strerror(errno)), 1);
      if (waitpid(pid, &status, 0) == -1)
	return (fprintf(stderr, strerror(errno)), 1);
    }
  /*fprintf(stderr, "exit_group(%d)\n", WSTOPSIG(status));*/
  fprintf(stderr, "+++ exited with %d +++\n", WSTOPSIG(status));
  /*if (ptrace(PTRACE_DETACH, pid, NULL, NULL) == -1)*/
    /*return (fprintf(stderr, strerror(errno)), 1);*/
  return (0);
}

