/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Sun Apr 03 18:41:19 2016 Bastien DHIVER
*/

#include <sys/user.h>
#include <stdio.h>
#include "strace.h"
#include "syscalls.h"

void	main_printing(t_regs *regs, t_bool details)
{
  (void)details;
  int	print_cur;

  print_cur = PRINT_SPACE;
  print_cur -= print("%s() ", g_syscalls[regs->orig_rax].name);
  while (--print_cur >= 0)
    printf(" ");
  printf("= ");
  printf("0x%llx\n", regs->rax);
}
