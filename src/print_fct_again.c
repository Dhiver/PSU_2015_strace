/*
** print_fct_again.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Wed Apr 06 00:33:11 2016 Bastien DHIVER
** Last update Sun Apr 10 20:07:10 2016 Bastien DHIVER
*/

#include "strace.h"

int	print_size_t(long_stuff value, void *call)
{
  (void)call;
  return (print("%ld", (size_t)value));
}

int	print_two_int(long_stuff value, void *call)
{
  int	*int_tab;

  (void)call;
  int_tab = (int *)value;
  return (print("[%d, %d]", int_tab[0], int_tab[1]));
}

int	print_usi_l(long_stuff value, void *call)
{
  (void)call;
  return (print("%lu", (unsigned long)value));
}

int	print_strstr(long_stuff value, void *call)
{
  (void)call;
  return (print("0x%llx", value));
}

int	print_long(long_stuff value, void *call)
{
  (void)call;
  return (print("%ld", (long)value));
}
