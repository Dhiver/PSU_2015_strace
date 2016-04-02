/*
** strace.h for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:18:57 2016 Bastien DHIVER
** Last update Sat Apr 02 22:37:20 2016 Bastien DHIVER
*/

#ifndef	STRACE_H_
# define STRACE_H_

# include <unistd.h>

# define USAGE		"Usage : ./strace [-s] [-p <pid>|<command>]\n"

extern pid_t		g_pid;

typedef	struct		s_args
{
  int			details;
  char			**av;
  char			**ae;
}			t_args;

int			display_error(int, int);
int			get_nbr(char *, long int *);
int			be_the_parent(int);
int			be_the_child(char **, char **);

/*
** signals.c
*/
void			get_sigint(int);


#endif /* !STRACE_H_ */
