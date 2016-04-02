/*
** signals.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Sat Apr 02 22:31:08 2016 Bastien DHIVER
** Last update Sat Apr 02 22:41:30 2016 Bastien DHIVER
*/

#include <stdio.h>
#include <stdlib.h>
#include "strace.h"

void	get_sigint(int sig)
{
  (void)sig;
  fprintf(stderr, "Process %d detached\n", g_pid);
  fprintf(stderr, " <detached ...>\n");
  exit(0);
}
