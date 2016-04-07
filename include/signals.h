/*
** signal.h for strace in /home/videau_f/rendu/PSU/PSU_2015_strace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Wed Apr  6 23:13:15 2016 florian videau
** Last update Thu Apr 07 23:19:15 2016 Bastien DHIVER
*/

#ifndef SIGNALS_H_
# define SIGNALS_H_

# include <signal.h>

#ifndef SI_ASYNCNL
# define SI_ASYNCNL	SI_ASYNCNL
#endif
#ifndef SI_TKILL
# define SI_TKILL	SI_TKILL
#endif
#ifndef SI_SIGIO
# define SI_SIGIO	SI_SIGIO
#endif
#ifndef SI_ASYNCIO
# define SI_ASYNCIO	SI_ASYNCIO
#endif
#ifndef SI_MESGQ
# define SI_MESGQ	SI_MESGQ
#endif
#ifndef SI_TIMER
# define SI_TIMER	SI_TIMER
#endif
#ifndef SI_QUEUE
# define SI_QUEUE	SI_QUEUE
#endif
#ifndef SI_USER
# define SI_USER	SI_USER
#endif
#ifndef SI_KERNEL
# define SI_KERNEL	SI_KERNEL
#endif
#ifndef ILL_ILLOPC
# define ILL_ILLOPC	ILL_ILLOPC
#endif
#ifndef ILL_ILLOPN
# define ILL_ILLOPN	ILL_ILLOPN
#endif
#ifndef ILL_ILLADR
# define ILL_ILLADR	ILL_ILLADR
#endif
#ifndef ILL_ILLTRP
# define ILL_ILLTRP	ILL_ILLTRP
#endif
#ifndef ILL_PRVOPC
# define ILL_PRVOPC	ILL_PRVOPC
#endif
#ifndef ILL_PRVREG
# define ILL_PRVREG	ILL_PRVREG
#endif
#ifndef ILL_COPROC
# define ILL_COPROC	ILL_COPROC
#endif
#ifndef ILL_BADSTK
# define ILL_BADSTK	ILL_BADSTK
#endif
#ifndef FPE_INTDIV
# define FPE_INTDIV	FPE_INTDIV
#endif
#ifndef FPE_INTOVF
# define FPE_INTOVF	FPE_INTOVF
#endif
#ifndef FPE_FLTDIV
# define FPE_FLTDIV	FPE_FLTDIV
#endif
#ifndef FPE_FLTOVF
# define FPE_FLTOVF	FPE_FLTOVF
#endif
#ifndef FPE_FLTUND
# define FPE_FLTUND	FPE_FLTUND
#endif
#ifndef FPE_FLTRES
# define FPE_FLTRES	FPE_FLTRES
#endif
#ifndef FPE_FLTINV
# define FPE_FLTINV	FPE_FLTINV
#endif
#ifndef FPE_FLTSUB
# define FPE_FLTSUB	FPE_FLTSUB
#endif
#ifndef SEGV_MAPERR
# define SEGV_MAPERR	SEGV_MAPERR
#endif
#ifndef SEGV_ACCERR
# define SEGV_ACCERR	SEGV_ACCERR
#endif
#ifndef BUS_ADRALN
# define BUS_ADRALN	BUS_ADRALN
#endif
#ifndef BUS_ADRERR
# define BUS_ADRERR	BUS_ADRERR
#endif
#ifndef BUS_OBJERR
# define BUS_OBJERR	BUS_OBJERR
#endif
#ifndef BUS_MCEERR_AR
# define BUS_MCEERR_AR	BUS_MCEERR_AR
#endif
#ifndef BUS_MCEERR_AO
# define BUS_MCEERR_AO	BUS_MCEERR_AO
#endif
#ifndef TRAP_BRKPT
# define TRAP_BRKPT	TRAP_BRKPT
#endif
#ifndef TRAP_TRACE
# define TRAP_TRACE	TRAP_TRACE
#endif
#ifndef CLD_EXITED
# define CLD_EXITED	CLD_EXITED
#endif
#ifndef CLD_KILLED
# define CLD_KILLED	CLD_KILLED
#endif
#ifndef CLD_DUMPED
# define CLD_DUMPED	CLD_DUMPED
#endif
#ifndef CLD_TRAPPED
# define CLD_TRAPPED	CLD_TRAPPED
#endif
#ifndef CLD_STOPPED
# define CLD_STOPPED	CLD_STOPPED
#endif
#ifndef CLD_CONTINUED
# define CLD_CONTINUED	CLD_CONTINUED
#endif
#ifndef POLL_IN
# define POLL_IN	POLL_IN
#endif
#ifndef POLL_OUT
# define POLL_OUT	POLL_OUT
#endif
#ifndef POLL_MSG
# define POLL_MSG	POLL_MSG
#endif
#ifndef POLL_ERR
# define POLL_ERR	POLL_ERR
#endif
#ifndef POLL_PRI
# define POLL_PRI	POLL_PRI
#endif
#ifndef POLL_HUP
# define POLL_HUP	POLL_HUP
#endif

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
