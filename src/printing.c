/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Sun Apr 10 15:08:56 2016 Bastien DHIVER
*/

#include <sys/user.h>
#include <stdio.h>
#include <string.h>
#include "strace.h"
#include "syscalls.h"
#include "errnoent.h"

int		print_arg(t_types type, long_stuff value, t_bool details,
			  t_bool is_child)
{
  t_pr_type	tab[E_END + 1];

  if (!details)
    type = E_ADDR;
  init_pr_type(tab);
  return (tab[type].ft_p(value, details, is_child));
}

void	print_execve(t_args *args)
{
  int	written;

  written = 0;
  written += print("execve(");
  written += print_arg(E_STR, (long_stuff)args->av[0], args->details, FALSE);
  written += print(", ");
  written += print_arg(E_STRSTR, (long_stuff)args->av, args->details, FALSE);
  written += print(", ");
  written += print_arg(E_STRSTR, (long_stuff)args->ae, args->details, FALSE);
  written += print(")");
  while (++written <= PRINT_SPACE)
    print(" ");
  print(" = ");
  print_arg(E_INT, (long_stuff)0, args->details, FALSE);
  print("\n");
}

void	print_ret(t_types type, long_stuff value, t_bool details)
{
  int	i;

  if (type == E_UNKN && print("?"))
    return ;
  i = -1;
  if (details == FALSE)
    print_arg(type, value, details, TRUE);
  else
    {
      if ((long)value >= 0)
	print_arg(type, value, details, TRUE);
      else
	while (g_errnoent[++i].nbr != -1)
	  if (-(long)value == g_errnoent[i].nbr)
	    print("-1 %s (%s)", g_errnoent[i].name, strerror(-(long)value));
    }
}

int	print_syscall(int syscall)
{
  int	i;

  i = -1;
  while (strcmp(g_syscalls[++i].name, "") != 0)
    if (i == syscall)
      return (print("%s(", g_syscalls[syscall].name));
  return (print("Unimplemented syscall : %d\n", syscall), 0);
}

void		main_printing(t_regs *regs, t_bool details)
{
  int		print_cur;
  long_stuff	r[7];
  int		i;
  int		during;

  i = -1;
  init_regs_tab(r, regs);
  print_cur = PRINT_SPACE;
  if ((print_cur -= print_syscall((int)regs->orig_rax)) == PRINT_SPACE)
    return ;
  during = strlen(g_syscalls[regs->orig_rax].args);
  while (++i < during)
    {
      print_cur -= print_arg(g_syscalls[regs->orig_rax].args[i] - '0',
			     r[i], details, TRUE);
      if (i != during - 1)
	print_cur -= print(", ");
    }
  print_cur -= print(")");
  while (--print_cur > 0)
    print(" ");
  print(" = ");
  print_ret(g_syscalls[regs->orig_rax].ret, regs->rax, details);
  print("\n");
}
