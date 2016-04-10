/*
** print_fct.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Apr 05 21:11:06 2016 Bastien DHIVER
** Last update Sun Apr 10 21:37:11 2016 Bastien DHIVER
*/

#include "strace.h"

int	print_unkn(long_stuff value, void *call)
{
  (void)value;
  (void)call;
  return (0);
}

int	print_int(long_stuff value, void *call)
{
  (void)call;
  return (print("%d", (int)value));
}

int	print_addr(long_stuff value, void *call_addr)
{
  t_call	*call;

  call = call_addr;
  if (call->details && value == 0)
    return (print("NULL"));
  return (print("0x%llx", value));
}

int	print_struc(long_stuff value, void *call_addr)
{
  t_call	*call;

  call = call_addr;
  if (!call->details)
    return (print("0x%llx", value));
  else
    return (print("{0x%llx}", value));
}
