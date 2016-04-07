/*
** init_tabs.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Apr 07 16:58:31 2016 Bastien DHIVER
** Last update Thu Apr 07 17:26:06 2016 Bastien DHIVER
*/

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

