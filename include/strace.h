/*
** strace.h for strace in /home/work/work/projects/PSU_2015_strace_doc/tests
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Thu Mar 31 13:18:57 2016 Bastien DHIVER
** Last update Sun Apr 10 20:06:33 2016 Bastien DHIVER
*/

#ifndef	STRACE_H_
# define STRACE_H_

# include <stdio.h>
# include <sys/types.h>
# include <sys/user.h>
# include <syscalls.h>

# define USAGE			"Usage : ./strace [-s] [-p <pid>|<command>]\n"
# define PRINT_SPACE		(40)
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
  int				(*ft_p)(long_stuff, void *);
}				t_pr_type;

typedef struct			s_call
{
  t_pr_type			pr_type[E_END + 1];
  t_regs			regs;
  long_stuff			args_val[7];
  t_bool			details;
  t_bool			is_child;
}				t_call;

/*
** utils.c
*/
int				display_error(int, int);
int				get_nbr(char *, long int *);

/*
** trace.c
*/
int				be_the_parent(t_call *);
int				be_the_child(t_args *, t_call *);

/*
** signals.c
*/
void				get_sigint(int);

/*
** printing.c
*/
void				main_printing(t_call *);
void				print_execve(t_args *, t_call *);

/*
** print_fct.c
*/
int				print_unkn(long_stuff, void *);
int				print_int(long_stuff, void *);
int				print_str(long_stuff, void *);
int				print_addr(long_stuff, void *);
int				print_struc(long_stuff, void *);

/*
** print_fct_again.c
*/
int				print_size_t(long_stuff, void *);
int				print_two_int(long_stuff, void *);
int				print_usi_l(long_stuff, void *);
int				print_strstr(long_stuff, void *);
int				print_long(long_stuff, void *);

/*
** find_executable.c
*/
char				*find_executable(char *);

/*
** init_tabs.c
*/
void				init_regs_tab(t_call *);
void				init_pr_type(t_pr_type *);

/*
** print_signals.c
*/
int				aff_end(int);

#endif /* !STRACE_H_ */
