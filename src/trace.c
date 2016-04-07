/*
** trace.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:41:06 2016 Bastien DHIVER
** Last update Thu Apr  7 13:43:06 2016 florian videau
*/

#define _GNU_SOURCE
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <strings.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my_signal.h"
#include "strace.h"

int	be_the_child(t_args *args)
{
  print_execve(args);
  if (ptrace(PTRACE_TRACEME, 0, NULL, NULL) == -1)
    return (display_error(errno, 1));
  if (execve(args->av[0], args->av, args->ae) == -1)
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

int		aff_end(int status)
{
  siginfo_t	info;

  if (WIFEXITED(status))
    {
      if (!(WSTOPSIG(status) == SIGSEGV))
	print("+++ exited with %d +++\n", WSTOPSIG(status));
      return (0);
    }
  else if (WIFSTOPPED(status))
    {
      ptrace(PTRACE_GETSIGINFO, g_pid, NULL, &info);
      if (info.si_signo != SIGTRAP && info.si_signo != SIGSTOP)
	{
	  print("--- %s {si_signo=%s", si_signo[info.si_signo],
		si_signo[info.si_signo]);
	  print(", si_code=%s,", info.si_code==128?"SI_KERNEL":
		(info.si_code < 0 ? si_code[-info.si_code]:
		 (info.si_signo == SIGILL ? si_code_ill[info.si_code] :
		  (info.si_signo == SIGFPE ? si_code_fpe[info.si_code] :
		   (info.si_signo == SIGSEGV ? si_code_segv[info.si_code] :
		    (info.si_signo == SIGBUS ? si_code_BUS[info.si_code] :
		     (info.si_signo == SIGTRAP ? si_code_trap[info.si_code] :
		      (info.si_signo == SIGCLD ? si_code_cld[info.si_code] :
		       (info.si_signo == SIGPOLL ? si_code_poll[info.si_code] :
			(""))))))))));
  	  /* print ("si_addr=0x??} ---\n"); */
  	  /* print("+++ killed by SIGSEGV +++\n"); */
  	  return (0);

	}
    }
  /* else if ((WIFSTOPPED(status) && WSTOPSIG(status) != SIGTRAP))*/
  /*   { */
  /*     if (WSTOPSIG(status) == SIGSEGV) */
  /* 	{ */
  /* 	  print("--- SIGSEGV {si_signo=SIGSEGV, si_code=SEGV_MAPERR,"); */
  /* 	  print ("si_addr=0x??} ---\n"); */
  /* 	  print("+++ killed by SIGSEGV +++\n"); */
  /* 	  return (0); */
  /* 	} */
  /*   } */
  return (1);
}

int	be_the_parent(t_bool details)
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
	return 0;
      if (inspect_regs(g_pid, details))
	return (1);
      if (ptrace(PTRACE_SINGLESTEP, g_pid, NULL, NULL) == -1)
	return (display_error(errno, 1));
      if (waitpid(g_pid, &status, 0) == -1)
	return (display_error(errno, 1));
    }
}
