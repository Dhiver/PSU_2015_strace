/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Tue Apr  5 16:11:25 2016 florian videau
*/

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <errno.h>
#include <sys/user.h>
#include "strace.h"

int	be_the_child(char **av, char **ae)
{
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno, 1));
  if (execve(av[0], av, ae) == -1)
    return (display_error(errno, 1));
  return (1);
}

int		inspect_regs(pid_t pid, t_bool details)
{
  t_regs	regs;

  bzero(&regs, sizeof(regs));
  if (ptrace(PTRACE_GETREGS, pid, NULL, &regs) == -1)
    return (display_error(errno, 1));
  if ((long long)regs.orig_rax != -1)
    main_printing(&regs, details);
  return (0);
}

int	be_the_parent(t_bool details)
{
  int	status;

  if (waitpid(g_pid, &status, 0) == -1)
    return (display_error(errno, 1));
  while (1)
    {
      if (!status || WIFEXITED(status))
	break;
      else if ((WIFSTOPPED(status) && WSTOPSIG(status) != SIGTRAP))
	{
	  if (WSTOPSIG(status) == SIGSEGV)
	    print("--- SIGSEGV {si_signo=SIGSEGV, si_code=SEGV_MAPERR, si_addr=0x2a} ---\n");
	  break;
	}
      if (inspect_regs(g_pid, details))
	return (1);
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno, 1));
      if (waitpid(g_pid, &status, 0) == -1)
      	return (display_error(errno, 1));
      print("%d\n", status);
    }
  if (WSTOPSIG(status) == SIGSEGV)
    print("+++ killed by SIGSEGV +++\n");
  else
    print("+++ exited with %d +++\n", WSTOPSIG(status));
  return (0);
}
