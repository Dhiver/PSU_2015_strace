/*
** strace.h for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:18:57 2016 Bastien DHIVER
** Last update Tue Apr  5 14:43:11 2016 florian videau
*/

#ifndef	STRACE_H_
# define STRACE_H_

# include <sys/types.h>
# include <sys/user.h>

# define USAGE			"Usage : ./strace [-s] [-p <pid>|<command>]\n"
# define PRINT_SPACE		(39)
# define DEFAULT_PATH		"/usr/local/bin:/usr/bin:/bin"

# define print(...)		fprintf (stderr, __VA_ARGS__)

typedef	enum			e_bool
{
  FALSE,
  TRUE
}				t_bool;

extern pid_t			g_pid;
extern t_bool			g_attach;

typedef	struct user_regs_struct	t_regs;

typedef unsigned long long int	long_stuff;

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

/*
** find_executable.c
*/
char				*find_executable(char *);


#endif /* !STRACE_H_ */
