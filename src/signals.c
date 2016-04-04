/*
** signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Apr 02 22:31:08 2016 Bastien DHIVER
** Last update Mon Apr 04 12:58:07 2016 Bastien DHIVER
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
  if (g_attach)
    if (ptrace(PTRACE_DETACH, g_pid, NULL, NULL) == -1)
      display_error(errno, 0);
  print("Process %d detached\n", g_pid);
  print(" <detached ...>\n");
  if (!g_attach)
    exit(0);
}

