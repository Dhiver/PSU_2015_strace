/*
** regs.c for regs in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:27:31 2016 Bastien DHIVER
** Last update Thu Mar 31 13:59:53 2016 Bastien DHIVER
*/

#include <sys/ptrace.h>
#include <sys/user.h>
#include <unistd.h>
#include <errno.h>
#include "strace.h"

int	get_regs(pid_t pid, struct user_regs_struct *regs)
{
  if (ptrace(PTRACE_GETREGS, pid, NULL, (void*)&regs))
    return (display_error(errno, -1));
  return (0);
}
