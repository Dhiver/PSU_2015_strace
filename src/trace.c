/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Sun Apr 10 19:50:02 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <errno.h>
#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "strace.h"

int	be_the_child(t_args *args, t_call *call)
{
  call->is_child = FALSE;
  print_execve(args, call);
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno, 1));
  if (execve(args->av[0], args->av, args->ae) == -1)
    return (display_error(errno, 1));
  return (1);
}

int		inspect_regs(t_call *call)
{
  if (ptrace(PTRACE_GETREGS, g_pid, NULL, &call->regs) == -1)
    return (display_error(errno, 1));
  if ((long long)call->regs.orig_rax != -1)
    main_printing(call);
  return (0);
}

int	be_the_parent(t_call *call)
{
  int	status;

  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno, 1));
  if (g_attach == FALSE)
    {
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno, 1));
      if (waitpid(g_pid, &status, 0) == -1)
	return (display_error(errno, 1));
    }
  while (1)
    {
      if (!aff_end(status))
	return (0);
      if (inspect_regs(call))
	return (1);
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno, 1));
      if (waitpid(g_pid, &status, 0) == -1)
	return (display_error(errno, 1));
    }
}
