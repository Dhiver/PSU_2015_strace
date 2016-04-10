/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Sun Apr 10 20:20:24 2016 Bastien DHIVER
*/

#include <sys/user.h>
#include <stdio.h>
#include <string.h>
#include "strace.h"
#include "errnoent.h"

int		print_arg(t_types type, long_stuff value, t_call *call)
{
  if (!call->details)
    type = E_ADDR;
  return (call->pr_type[type].ft_p(value, call));
}

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

void		print_ret(t_call *call)
{
  int		i;
  t_types	type;

  type = g_syscalls[call->regs.orig_rax].ret;
  if (type == E_UNKN && print("?"))
    return ;
  i = -1;
  if (call->details == FALSE)
    print_arg(type, call->regs.rax, call);
  else
    {
      if ((long)call->regs.rax >= 0)
	print_arg(type, call->regs.rax, call);
      else
	while (g_errnoent[++i].nbr != -1)
	  if (-(long)call->regs.rax == g_errnoent[i].nbr)
	    print("-1 %s (%s)", g_errnoent[i].name,
		  strerror(-(long)call->regs.rax));
    }
}

int	print_syscall_name(int syscall)
{
  int	i;

  i = -1;
  while (strcmp(g_syscalls[++i].name, "") != 0)
    if (i == syscall)
      return (print("%s", g_syscalls[syscall].name));
  return (print("Unimplemented syscall : %d\n", syscall), 0);
}

int	print_arg_loop(t_call *call, int during)
{
  int	i;
  int	print_cur;

  i = -1;
  print_cur = 0;
  while (++i < during)
    {
      print_cur += print_arg(g_syscalls[call->regs.orig_rax].args[i] - '0',
			     call->args_val[i], call);
      if (i != during - 1)
	print_cur += print(", ");
    }
  return (print_cur);
}

void		main_printing(t_call *call)
{
  int		print_cur;
  int		res;

  init_regs_tab(call);
  print_cur = PRINT_SPACE;
  if ((res = print_syscall_name((int)call->regs.orig_rax)) == 0)
    return ;
  print_cur -= res;
  print_cur -= print("(");
  print_cur -= print_arg_loop(call,
			      strlen(g_syscalls[call->regs.orig_rax].args));
  print_cur -= print(")");
  while (--print_cur > 0)
    print(" ");
  print(" = ");
  print_ret(call);
  print("\n");
}
