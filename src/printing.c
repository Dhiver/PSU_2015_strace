/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Thu Apr 07 13:04:30 2016 Bastien DHIVER
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

void	init_pr_type(t_pr_type *tab)
{
  tab[E_UNKN].ft_p = &print_unkn;
  tab[E_INT].ft_p = &print_int;
  tab[E_STR].ft_p = &print_str;
  tab[E_ADDR].ft_p = &print_addr;
  tab[E_STRUC].ft_p = &print_struc;
  tab[E_SIZE_T].ft_p = &print_size_t;
  tab[E_INT_2].ft_p = &print_two_int;
  tab[E_USI_L].ft_p = &print_usi_l;
  tab[E_STRSTR].ft_p = &print_strstr;
  tab[E_LONG].ft_p = &print_long;
  tab[E_END].ft_p = NULL;
}

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
  if (type == E_UNKN && print("?"))
    return ;
  print_arg(type, value, details, TRUE);
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
  print_cur -= print("%s(", g_syscalls[regs->orig_rax].name);
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
