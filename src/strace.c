/*
** tp-strace-ex2.c for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:19:04 2016 Bastien DHIVER
** Last update Sat Apr 02 23:01:22 2016 Bastien DHIVER
*/

#include <errno.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "strace.h"

pid_t	g_pid = 0;

int	display_usage(void)
{
  return (fprintf(stderr, USAGE), 1);
}

int		get_args(int ac, char **av, t_args *args)
{
  int		opt;
  long int	p;

  optind = 1;
  args->details = 0;
  while ((opt = getopt(ac, av, "sp:")) != -1)
    {
      if (opt == 's')
	args->details = 1;
      else if (opt == 'p')
	{
	  if (get_nbr(optarg, &p) || p <= 1)
	    return (display_usage());
	  g_pid = (pid_t)p;
	}
      else
	return (display_usage());
    }
  args->av = av + 1;
  return (0);
}

int	run_process(t_args *args)
{
  int	details;

  details = args->details;
  if ((g_pid = fork()) == 1)
    return (display_error(errno, 1));
  if (g_pid == 0)
    return (be_the_child(args->av, args->ae));
  else
    return (be_the_parent(details));
}

int	attach_process(int details)
{
  if (ptrace(PTRACE_ATTACH, g_pid, NULL, NULL) == -1)
    return (display_error(errno, 1));
  fprintf(stderr, "Process %d attached\n", g_pid);
  return (be_the_parent(details));
}

int		main(int ac, char **av, char **ae)
{
  t_args	args;

  if (ac < 2)
    return (display_usage());
  signal(SIGINT, get_sigint);
  bzero(&args, sizeof(args));
  args.ae = ae;
  if (get_args(ac, av, &args))
    return (1);
  if (g_pid != 0)
    return (attach_process(args.details));
  else
    return (run_process(&args));
  return (0);
}
