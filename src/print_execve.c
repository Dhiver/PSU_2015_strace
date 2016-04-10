/*
** print_execve.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 10 21:39:23 2016 Bastien DHIVER
** Last update Sun Apr 10 21:40:16 2016 Bastien DHIVER
*/

#include "strace.h"

void	print_execve(t_args *args, t_call *call)
{
  int	written;

  written = 0;
  written += print("execve(");
  written += print_arg(E_STR, (long_stuff)args->av[0], call);
  written += print(", ");
  written += print_arg(E_STRSTR, (long_stuff)args->av, call);
  written += print(", ");
  written += print_arg(E_STRSTR, (long_stuff)args->ae, call);
  written += print(")");
  while (++written <= PRINT_SPACE)
    print(" ");
  print(" = ");
  print_arg(E_INT, (long_stuff)0, call);
  print("\n");
}

