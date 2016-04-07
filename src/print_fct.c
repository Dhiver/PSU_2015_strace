/*
** print_fct.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Apr 05 21:11:06 2016 Bastien DHIVER
** Last update Thu Apr 07 23:39:02 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <string.h>
#include "strace.h"

int	print_unkn(long_stuff value, t_bool details, t_bool is_child)
{
  (void)details;
  (void)value;
  (void)is_child;
  return (0);
}

int	print_int(long_stuff value, t_bool details, t_bool is_child)
{
  (void)details;
  (void)is_child;
  return (print("%d", (int)value));
}

int	print_str(long_stuff value, t_bool details, t_bool is_child)
{
  int	written;
  long	data;
  int	i;

  written = 0;
  i = 0;
  if (details && is_child)
    {
      data = ptrace(PTRACE_PEEKDATA, g_pid, value + i * sizeof(char), NULL);
      written += print("\"");
      while ((char)data != 0 && written != MAX_PRINT_CHAR && (i += 1))
	{
	  written += print("%c", (char)data);
	  data = ptrace(PTRACE_PEEKDATA, g_pid, value + i * sizeof(char), NULL);
	}
      written += print("\"");
      if (written == MAX_PRINT_CHAR + 1)
	written += print("...");
      return (written);
    }
  else if (details)
    return (print("\"%s\"", (char *)value));
  return (0);
}

int	print_addr(long_stuff value, t_bool details, t_bool is_child)
{
  (void)is_child;
  if (details && value == 0)
    return (print("0"));
  return (print("0x%llx", value));
}

int	print_struc(long_stuff value, t_bool details, t_bool is_child)
{
  (void)details;
  (void)is_child;
  if (!details)
    return (print("0x%llx", value));
  else
    return (print("{0x%llx}", value));
}
