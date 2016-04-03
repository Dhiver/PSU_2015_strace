/*
** printing.c for printing in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sun Apr 03 12:36:29 2016 Bastien DHIVER
** Last update Sun Apr 03 14:55:42 2016 Bastien DHIVER
*/

#include <sys/user.h>
#include <stdio.h>
#include "strace.h"
#include "syscalls.h"

void	main_printing(struct user_regs_struct *regs, int details)
{
  (void)details;
  print("%s() %39s%llx\n", g_syscalls[regs->orig_rax].name, "= 0x", regs->rax);
}
