/*
** signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Apr 02 22:31:08 2016 Bastien DHIVER
** Last update Sun Apr 03 14:55:19 2016 Bastien DHIVER
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/ptrace.h>
#include "strace.h"

void	get_sigint(int sig)
{
  (void)sig;
  if (ptrace(PTRACE_DETACH, g_pid, NULL, NULL) == -1)
    print(strerror(errno));
  print("Process %d detached\n", g_pid);
  print(" <detached ...>\n");
  exit(0);
}
