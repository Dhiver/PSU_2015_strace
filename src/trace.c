/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Sun Apr 03 12:35:17 2016 Bastien DHIVER
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
#include "syscalls.h"

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
    printf("%s() %39s%llx\n", g_syscalls[regs.orig_rax].name, "= 0x", regs.rax);
  return (0);
}

int	be_the_parent(int details)
{
  int	status;

  (void)details;
  if (waitpid(g_pid, &status, 0) == -1)
    return (fprintf(stderr, strerror(errno)), 1);
  while (WIFSTOPPED(status))
    {
      if (inspect_regs(g_pid))
	return (1);
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (fprintf(stderr, strerror(errno)), 1);
      if (waitpid(g_pid, &status, 0) == -1)
	return (fprintf(stderr, strerror(errno)), 1);
    }
  fprintf(stderr, "+++ exited with %d +++\n", WSTOPSIG(status));
  return (0);
}

