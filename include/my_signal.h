/*
** signal.h for strace in /home/videau_f/rendu/PSU/PSU_2015_strace
**
** Made by florian videau
** Login   <videau_f@epitech.net>
**
** Started on  Wed Apr  6 23:13:15 2016 florian videau
** Last update Thu Apr  7 02:28:31 2016 florian videau
*/

#ifndef SIGNAL_H_
# define SIGNAL_H_

const	char	si_signo[][9] =
  {
    {""},
    {"SIGHUP"},
    {"SIGTERM"},
    {"SIGQUIT"},
    {"SIGILL"},
    {"SIGTRAP"},
    {"SIGABRT"},
    {"SIGBUS"},
    {"SIGFPE"},
    {"SIGKILL"},
    {"SIGUSR1"},
    {"SIGSEGV"},
    {"SIGUSR2"},
    {"SIGPIPE"},
    {"SIGALRM"},
    {"SIGTERM"},
    {"SIGTKFLT"},
    {"SIGCHLD"},
    {"SIGCONT"},
    {"SIGSTOP"},
    {"SIGTSTP"},
    {"SIGTTIN"},
    {"SIGTTOU"},
    {"SIGURG"},
    {"SIGXCPU"},
    {"SIGXFSZ"},
    {"SIGVTALRM"},
    {"SIGPROF"},
    {"SIGWINCH"},
    {"SIGPOLL"},
    {"SIGPWR"},
    {"SIGSYS"},
  };

/* SI_KERNEL : 128 */
const	char	si_code[][11] =
  {
    {"SI_USR"},
    {"SI_QUEUE"},
    {"SI_TIMER"},
    {"SI_MESGQ"},
    {"SI_ASYNCIO"},
    {"SI_SIGIO"},
    {"SI_TKILL"}
  };

const	char	si_code_ill[][11] =
  {
    {""},
    {"ILL_ILLOPC"},
    {"ILL_ILLOPN"},
    {"ILL_ILADDR"},
    {"ILL_ILLTRP"},
    {"ILL_PRVOPC"},
    {"ILL_PRVREG"},
    {"ILL_COROC"},
    {"ILL_BADSTK"},
  };

const	char	si_code_fpe[][11] =
  {
    {""},
    {"FPE_INTDIV"},
    {"FPE_INTOVF"},
    {"FPE_FLTDIV"},
    {"FPE_FLTOVF"},
    {"FPE_FLTUND"},
    {"FPE_FLTRES"},
    {"FPE_FLTSUB"}
  };

const	char	si_code_segv[][11] =
  {
    {""},
    {"SEGV_MAPERR"},
    {"SEGV_ACCERR"}
  };

const	char	si_code_bus[][15] =
  {
    {""},
    {"BUS_ADRALN"},
    {"BUS_ADRERR"},
    {"BUS_OBJERR"},
    {"BUS_MCEERR_AR"},
    {"BUS_MCEERR_AO"}
  };

const	char	si_code_trap[][11] =
  {
    {""},
    {"TRAP_BRKPT"},
    {"TRAP_TRACE"}
  };

const	char	si_code_cld[][13] =
  {
    {""},
    {"CLD_EXITED"},
    {"CLD_KILLED"},
    {"CLD_DUMPED"},
    {"CLD_TRAPPED"},
    {"CLD_STOPPED"},
    {"CLD_CONTINUED"}
  };

const	char	si_code_poll[][11] =
  {
    {""},
    {"POLL_IN"},
    {"POLL_OUT"},
    {"POLL_MSG"},
    {"POLL_ERR"},
    {"POLL_PRI"},
    {"POLL_HUP"}
  };


#endif /* SIGNAL_H_*/
