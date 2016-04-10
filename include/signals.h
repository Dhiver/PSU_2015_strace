/*
** signal.h for strace in /home/videau_f/rendu/PSU/PSU_2015_strace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Wed Apr  6 23:13:15 2016 florian videau
** Last update Sun Apr 10 12:48:51 2016 Bastien DHIVER
*/

#ifndef SIGNALS_H_
# define SIGNALS_H_

#define _GNU_SOURCE
# include <signal.h>

typedef	struct	s_signals
{
  int		nbr;
  char		*name;
}		t_signals;

typedef	struct	s_sig_groups
{
  int		idx;
  t_signals	group_name[10];
}		t_sig_groups;

const t_signals		g_signals[] =
{
    {SIGHUP, "SIGHUP"},
    {SIGTERM, "SIGTERM"},
    {SIGQUIT, "SIGQUIT"},
    {SIGILL, "SIGILL"},
    {SIGTRAP, "SIGTRAP"},
    {SIGABRT, "SIGABRT"},
    {SIGBUS, "SIGBUS"},
    {SIGFPE, "SIGFPE"},
    {SIGKILL, "SIGKILL"},
    {SIGUSR1, "SIGUSR1"},
    {SIGSEGV, "SIGSEGV"},
    {SIGUSR2, "SIGUSR2"},
    {SIGPIPE, "SIGPIPE"},
    {SIGALRM, "SIGALRM"},
    {SIGTERM, "SIGTERM"},
    {SIGSTKFLT, "SIGTKFLT"},
    {SIGCHLD, "SIGCHLD"},
    {SIGCONT, "SIGCONT"},
    {SIGSTOP, "SIGSTOP"},
    {SIGTSTP, "SIGTSTP"},
    {SIGTTIN, "SIGTTIN"},
    {SIGTTOU, "SIGTTOU"},
    {SIGURG, "SIGURG"},
    {SIGXCPU, "SIGXCPU"},
    {SIGXFSZ, "SIGXFSZ"},
    {SIGVTALRM, "SIGVTALRM"},
    {SIGPROF, "SIGPROF"},
    {SIGWINCH, "SIGWINCH"},
    {SIGPOLL, "SIGPOLL"},
    {SIGPWR, "SIGPWR"},
    {SIGSYS, "SIGSYS"},
    {-1, ""}
};

const t_signals		g_si_code[] =
{
    {SI_USER, "SI_USER"},
    {SI_QUEUE, "SI_QUEUE"},
    {SI_TIMER, "SI_TIMER"},
    {SI_MESGQ, "SI_MESGQ"},
    {SI_ASYNCIO, "SI_ASYNCIO"},
    {SI_SIGIO, "SI_SIGIO"},
    {SI_TKILL, "SI_TKILL"},
    {-1, ""}
};

const t_sig_groups	g_sig_groups[8]=
{
    {SIGILL, {
		 {ILL_ILLOPC, "ILL_ILLOPC"},
		 {ILL_ILLOPN, "ILL_ILLOPN"},
		 {ILL_ILLADR, "ILL_ILLADR"},
		 {ILL_ILLTRP, "ILL_ILLTRP"},
		 {ILL_PRVOPC, "ILL_PRVOPC"},
		 {ILL_PRVREG, "ILL_PRVREG"},
		 {ILL_COPROC, "ILL_COPROC"},
		 {ILL_BADSTK, "ILL_BADSTK"},
		 {-1, ""}}},
    {SIGFPE, {
		 {FPE_INTDIV, "FPE_INTDIV"},
		 {FPE_INTOVF, "FPE_INTOVF"},
		 {FPE_FLTDIV, "FPE_FLTDIV"},
		 {FPE_FLTOVF, "FPE_FLTOVF"},
		 {FPE_FLTUND, "FPE_FLTUND"},
		 {FPE_FLTRES, "FPE_FLTRES"},
		 {FPE_FLTSUB, "FPE_FLTSUB"},
		 {-1, ""}}},
    {SIGSEGV, {
		 {SEGV_MAPERR, "SEGV_MAPERR"},
		 {SEGV_ACCERR, "SEGV_ACCERR"},
		 {-1, ""}}},
    {SIGBUS, {
		 {BUS_ADRALN, "BUS_ADRALN"},
		 {BUS_ADRERR, "BUS_ADRERR"},
		 {BUS_OBJERR, "BUS_OBJERR"},
		 {BUS_MCEERR_AR, "BUS_MCEERR_AR"},
		 {BUS_MCEERR_AO, "BUS_MCEERR_AO"},
		 {-1, ""}}},
    {SIGTRAP, {
		 {TRAP_BRKPT, "TRAP_BRKPT"},
		 {TRAP_TRACE, "TRAP_TRACE"},
		 {-1, ""}}},
    {SIGCLD, {
		 {CLD_EXITED, "CLD_EXITED"},
		 {CLD_KILLED, "CLD_KILLED"},
		 {CLD_DUMPED, "CLD_DUMPED"},
		 {CLD_TRAPPED, "CLD_TRAPPED"},
		 {CLD_STOPPED, "CLD_STOPPED"},
		 {CLD_CONTINUED, "CLD_CONTINUED"},
		 {-1, ""}}},
    {SIGPOLL, {
		 {POLL_IN, "POLL_IN"},
		 {POLL_OUT, "POLL_OUT"},
		 {POLL_MSG, "POLL_MSG"},
		 {POLL_ERR, "POLL_ERR"},
		 {POLL_PRI, "POLL_PRI"},
		 {POLL_HUP, "POLL_HUP"},
		 {-1, ""}}},
    {-1, {
	     {-1, ""}}}
};

#endif /* SIGNALS_H_*/
