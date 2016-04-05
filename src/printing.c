/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Tue Apr 05 17:04:46 2016 Bastien DHIVER
*/

#include <sys/user.h>
#include <stdio.h>
#include <string.h>
#include "strace.h"
#include "syscalls.h"

void	init_regs_tab(long_stuff *r, t_regs *regs)
{
  r[0] = regs->rdi;
  r[1] = regs->rsi;
  r[2] = regs->rdx;
  r[3] = regs->r10;
  r[4] = regs->r8;
  r[5] = regs->r9;
  r[6] = 0;
}

int		display_args(t_regs *regs, t_bool details, int nb_args)
{
  long_stuff	r[7];

  int	print_cur;
  int	i;

  (void)details;
  init_regs_tab(r, regs);
  print_cur = 0;
  i = -1;
  while (++i < nb_args)
    {
      print_cur += print("0x%llx", r[i]);
      if (i != nb_args - 1)
	print_cur += print(", ");
    }
  return (print_cur);
}

void	display_ret(long_stuff ret, t_bool details)
{
  (void)details;
  print("0x%llx\n", ret);
}

void	print_execve(t_args *args)
{
  int	written;

  written = print("execve(0x%llx, 0x%llx, 0x%llx", (long_stuff)args->av[0],
		  (long_stuff)args->av, (long_stuff)args->ae);
  while (++written <= PRINT_SPACE)
    print(" ");
  print(") = 0x%llx\n", (long_stuff)0);
}

void		main_printing(t_regs *regs, t_bool details)
{
  int		print_cur;

  print_cur = PRINT_SPACE;
  print_cur -= print("%s(", g_syscalls[regs->orig_rax].name);
  print_cur -= display_args(regs, details,
			    strlen(g_syscalls[regs->orig_rax].args));
  print(")");
  while (--print_cur > 0)
    print(" ");
  print(" = ");
  display_ret(regs->rax, details);
}
