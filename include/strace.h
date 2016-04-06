/*
** strace.h for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:18:57 2016 Bastien DHIVER
** Last update Wed Apr 06 22:56:15 2016 Bastien DHIVER
*/

#ifndef	STRACE_H_
# define STRACE_H_

# include <stdio.h>
# include <sys/types.h>
# include <sys/user.h>

# define USAGE			"Usage : ./strace [-s] [-p <pid>|<command>]\n"
# define PRINT_SPACE		(39)
# define DEFAULT_PATH		"/usr/local/bin:/usr/bin:/bin"
# define MAX_PRINT_CHAR		(37)

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

typedef struct			s_pr_type
{
  int				(*ft_p)(long_stuff, t_bool);
}				t_pr_type;


/*
** utils.c
*/
int				display_error(int, int);
int				get_nbr(char *, long int *);

/*
** trace.c
*/
int				be_the_parent(t_bool);
int				be_the_child(t_args *);

/*
** signals.c
*/
void				get_sigint(int);

/*
** printing.c
*/
void				main_printing(t_regs *, t_bool);
void				print_execve(t_args *);

/*
** print_fct.c
*/
int				print_unkn(long_stuff, t_bool);
int				print_int(long_stuff, t_bool);
int				print_str(long_stuff, t_bool);
int				print_addr(long_stuff, t_bool);
int				print_struc(long_stuff, t_bool);

/*
** print_fct_again.c
*/
int				print_size_t(long_stuff, t_bool);
int				print_two_int(long_stuff, t_bool);
int				print_usi_l(long_stuff, t_bool);
int				print_strstr(long_stuff, t_bool);
int				print_long(long_stuff, t_bool);

/*
** find_executable.c
*/
char				*find_executable(char *);

#endif /* !STRACE_H_ */
