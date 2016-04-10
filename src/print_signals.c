/*
** print_signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 10 12:23:38 2016 Bastien DHIVER
** Last update Sun Apr 10 12:48:59 2016 Bastien DHIVER
*/

#define _GNU_SOURCE
#include <sys/ptrace.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include "strace.h"
#include "signals.h"

void	print_si_code(int signo, int code)
{
  int	i;
  int	j;

  i = -1;
  j = -1;
  if (code == SI_KERNEL)
    print("si_code=SI_KERNEL, ");
  else if (code <= 0)
    {
      while (g_si_code[++i].nbr != -1)
	if (g_si_code[i].nbr == code)
	  print("si_code=%s, ", g_si_code[i].name);
    }
  else
    while (g_sig_groups[++i].idx != -1)
      if (g_sig_groups[i].idx == signo)
	while (g_sig_groups[i].group_name[++j].nbr != -1)
	  if (g_sig_groups[i].group_name[j].nbr == code)
	    {
	      print("si_code=%s, ", g_sig_groups[i].group_name[j].name);
	      return ;
	    }
}

void	print_si_extra(siginfo_t *info)
{
  if (info->si_code > 0)
    print("si_addr=%p", info->si_addr);
  else
    print("si_pid=%d, si_uid=%d", info->si_pid, info->si_uid);
  print("} ---\n+++ killed by ");
}

void	aff_signal(siginfo_t *info)
{
  int	i;

  i = -1;
  while (g_signals[++i].nbr != -1)
    if (g_signals[i].nbr == info->si_signo)
      {
	print("%s {si_signo=%s, ", g_signals[i].name, g_signals[i].name);
	break;
      }
  print_si_code(info->si_signo, info->si_code);
  print_si_extra(info);
  print("%s +++\n", g_signals[i].name);
  kill(g_pid, info->si_signo);
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
      if (ptrace(PTRACE_GETSIGINFO, g_pid, NULL, &info))
	return (display_error(errno, 1));
      if (info.si_signo != SIGTRAP && info.si_signo != SIGSTOP)
	return (print("--- "), aff_signal(&info), 0);
    }
  return (1);
}

