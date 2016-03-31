/*
** tp-strace-ex2.c for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:19:04 2016 Bastien DHIVER
** Last update Thu Mar 31 14:35:39 2016 Bastien DHIVER
*/

#include <errno.h>
#include <stdio.h>
#include "strace.h"

int	display_usage(void)
{
  return (fprintf(stderr, USAGE), 1);
}

int		get_args(int ac, char **av, t_args *args)
{
  int		opt;
  long int	p;

  optind = 1;
  while ((opt = getopt(ac, av, "sp:")) != -1)
    {
      if (opt == 's')
	args->details = 1;
      else if (opt == 'p')
	{
	  if (get_nbr(optarg, &p) || args->pid <= 1)
	    return (display_usage());
	}
      else
	return (display_usage());
    }
  args->ac = ac - 1;
  args->av = av + 1;
  args->pid = (pid_t)p;
  return (0);
}

int		main(int ac, char **av, char **ae)
{
  pid_t		pid;
  t_args	args;

  if (ac < 2)
    return (display_usage());
  args.details = 0;
  args.pid = -1;
  args.ae = ae;
  if (get_args(ac, av, &args))
    return (1);
  if ((pid = fork()) == 1)
    return (display_error(errno, 1));
  if (pid == 0)
    return (do_child(&args));
  else
    return (do_trace(pid));
  return (0);
}
