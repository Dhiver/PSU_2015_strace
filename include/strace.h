/*
** strace.h for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:18:57 2016 Bastien DHIVER
** Last update Thu Mar 31 14:37:10 2016 Bastien DHIVER
*/

#ifndef	STRACE_H_
# define STRACE_H_

# include <unistd.h>
# include <string.h>
# include <sys/user.h>

# define CHILD_STOP	"Child stopped: %d\n"
# define CHILD_EXIT	"Child exited: %d\n"
# define CHILD_SIG	"Child signaled: %d\n"
# define CHILD_SEGV	"Core dumped\n"

# define USAGE		"Usage : ./strace [-s] [-p <pid>|<command>]\n"

typedef	struct		s_args
{
  int			details;
  pid_t			pid;
  int			ac;
  char			**av;
  char			**ae;
}			t_args;

int		display_error(int, int);
int		get_nbr(char *, long int *);
int		get_regs(pid_t, struct user_regs_struct *);
int		do_child(t_args *);
int		do_trace(pid_t);

#endif /* !STRACE_H_ */
