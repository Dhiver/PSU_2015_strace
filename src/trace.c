/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Thu Mar 31 14:51:11 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/user.h>
#include "strace.h"

void	print_wait_status(int status)
{
  if (WIFSTOPPED(status))
    fprintf(stderr, CHILD_STOP, WSTOPSIG(status));
  else if (WIFEXITED(status))
    fprintf(stderr, CHILD_EXIT, WEXITSTATUS(status));
  else if (WIFSIGNALED(status))
    fprintf(stderr, CHILD_STOP, WTERMSIG(status));
  else if (WCOREDUMP(status))
    fprintf(stderr, CHILD_SEGV);
}

int	do_child(t_args *args)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno, 1));
  if (kill(getpid(), SIGSTOP) == -1)
    return (display_error(errno, 1));
  return (execve(args->av[0], args->av, args->ae));
}

int				do_trace(pid_t pid)
{
  int				status;
  struct user_regs_struct	regs;

  waitpid(pid, &status, 0);
  print_wait_status(status);
  while (WIFSTOPPED(status))
    {
      if (get_regs(pid, &regs))
	break;
    }
  return (0);
}
