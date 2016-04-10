/*
** tp-strace-ex2.c for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:19:04 2016 Bastien DHIVER
** Last update Sun Apr 10 14:31:52 2016 Bastien DHIVER
*/

#include <errno.h>
#include <getopt.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include "strace.h"

pid_t	g_pid = 0;
t_bool	g_attach = FALSE;

int	display_usage(void)
{
  return (print(USAGE), 1);
}

int		get_args(int ac, char **av, t_args *args)
{
  int		opt;
  long int	p;

  optind = 1;
  args->details = FALSE;
  args->av = av + 1;
  while ((opt = getopt(ac, av, "sp:")) != -1)
    {
      if (opt == 's')
	args->details = TRUE;
      else if (opt == 'p')
	{
	  if (get_nbr(optarg, &p) || p <= 0)
	    return (display_usage());
	  g_pid = (pid_t)p;
	  g_attach = TRUE;
	}
      else
	return (display_usage());
    }
  if (args->details)
    args->av += 1;
  return (0);
}

int	run_process(t_args *args)
{
  char	*exec_name;

  if ((exec_name = find_executable(args->av[0])) == NULL)
    return (print("Can't find or execute %s\n", args->av[0]), 1);
  args->av[0] = exec_name;
  if ((g_pid = fork()) == 1)
    return (display_error(errno, 1));
  if (g_pid == 0)
    return (be_the_child(args));
  else
    return (be_the_parent(args->details));
  return (0);
}

int	attach_process(t_bool details)
{
  if (ptrace(PTRACE_ATTACH, g_pid, NULL, NULL) == -1)
    return (display_error(errno, 1));
  print("Process %d attached\n", g_pid);
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
  if (g_attach)
    return (attach_process(args.details));
  else
    return (run_process(&args));
  return (0);
}
