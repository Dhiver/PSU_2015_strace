/*
** strace.h for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
** 
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
** 
** Started on  Thu Mar 31 13:18:57 2016 Bastien DHIVER
** Last update Sun Apr 03 18:36:44 2016 Bastien DHIVER
*/

#ifndef	STRACE_H_
# define STRACE_H_

# include <unistd.h>
# include <sys/user.h>

# define USAGE			"Usage : ./strace [-s] [-p <pid>|<command>]\n"
# define PRINT_SPACE		(40)

# define print(...)		fprintf (stderr, __VA_ARGS__)

extern pid_t			g_pid;

typedef	struct user_regs_struct	t_regs;

typedef	enum			e_bool
{
  FALSE,
  TRUE
}				t_bool;

typedef	struct			s_args
{
  t_bool			details;
  char				**av;
  char				**ae;
}				t_args;

/*
** utils.c
*/
int				display_error(int, int);
int				get_nbr(char *, long int *);

/*
** trace.c
*/
int				be_the_parent(t_bool);
int				be_the_child(char **, char **);

/*
** signals.c
*/
void				get_sigint(int);

/*
** printing.c
*/
void				main_printing(t_regs *, t_bool);


#endif /* !STRACE_H_ */
