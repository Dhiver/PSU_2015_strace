/*
** print_strs.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 10 21:36:30 2016 Bastien DHIVER
** Last update Sun Apr 10 21:37:10 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <string.h>
#include <ctype.h>
#include "strace.h"

t_bool	is_printing_spec(int syscall)
{
      if (strcmp(g_syscalls[syscall].name, "read") == 0
	  || strcmp(g_syscalls[syscall].name, "write") == 0)
	return (TRUE);
      return (FALSE);
}

int		print_btw_quotes(long_stuff value, int *during)
{
  int		written;
  char		c;
  int		i;
  int		flag;

  written = 0;
  i = 0;
  flag = 1;
  c = (char)ptrace(PTRACE_PEEKDATA, g_pid, value + i * sizeof(char), NULL);
  while (written != *during && c != -1 && (i += 1))
    {
      if (!isprint(c) && c != 0)
	{
	  *during = MAX_PRINT_SPEC;
	  flag = 0;
	}
      else if (flag)
	if (c == 0)
	  break;
      written += isprint(c) ? print("%c", c) : print("\\%o", c);
      c = (char)ptrace(PTRACE_PEEKDATA, g_pid, value + i * sizeof(char),
		    NULL);
    }
  return (written);
}

int		print_str(long_stuff value, void *call_addr)
{
  int		written;
  t_call	*call;
  int		during;

  call = call_addr;
  during = MAX_PRINT_CHAR;
  written = 0;
  if (call->details && call->is_child)
    {
      written += print("\"");
      written += print_btw_quotes(value, &during);
      written += print("\"");
      if (written - 2 == during)
	written += print("...");
      return (written);
    }
  else if (call->details)
    return (print("\"%s\"", (char *)value));
  return (0);
}
