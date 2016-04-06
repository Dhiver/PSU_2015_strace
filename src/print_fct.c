/*
** print_fct.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Tue Apr 05 21:11:06 2016 Bastien DHIVER
** Last update Wed Apr 06 23:38:59 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <string.h>
#include "strace.h"

int	print_unkn(long_stuff value, t_bool details)
{
  (void)details;
  (void)value;
  return (0);
}

int	print_int(long_stuff value, t_bool details)
{
  (void)details;
  return (print("%d", (int)value));
}

int	print_str(long_stuff value, t_bool details)
{
  int	written;
  long	data;
  int	i;

  written = 0;
  i = 0;
  if (details)
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
  return (print("%s", (char *)value));
}

int	print_addr(long_stuff value, t_bool details)
{
  if (details && value == 0)
    return (print("0"));
  return (print("0x%llx", value));
}

int	print_struc(long_stuff value, t_bool details)
{
  (void)details;
  return (print("0x%llx", value));
}
