#include <signal.h>
#include <stdio.h>

int	main(void)
{
  printf("SIGHUP : %d\n", SIGHUP);
  printf("SIGINT : %d\n", SIGINT);
  printf("SIGQUIT : %d\n", SIGQUIT);
  printf("SIGILL : %d\n", SIGILL);
  printf("SIGABRT : %d\n", SIGABRT);
  printf("SIGFPE : %d\n", SIGFPE);
  printf("SIGKILL : %d\n", SIGKILL);
  printf("SIGSEGV : %d\n", SIGSEGV);
  printf("SIGPIPE : %d\n", SIGPIPE);
  printf("SIGALRM : %d\n", SIGALRM);
  printf("SIGTERM : %d\n", SIGTERM);
  printf("SIGUSR1 : %d\n", SIGUSR1);
  printf("SIGUSR2 : %d\n", SIGUSR2);
  printf("SIGCHLD : %d\n", SIGCHLD);
  printf("SIGCONT : %d\n", SIGCONT);
  printf("SIGSTOP : %d\n", SIGSTOP);
  printf("SIGTSTP : %d\n", SIGTSTP);
  printf("SIGTTIN : %d\n", SIGTTIN);
  printf("SIGTTOU : %d\n", SIGTTOU);
  printf("SIGBUS : %d\n", SIGBUS);
  printf("SIGPOLL : %d\n", SIGPOLL);
  printf("SIGPROF : %d\n", SIGPROF);
  printf("SIGSYS : %d\n", SIGSYS);
  printf("SIGTRAP : %d\n", SIGTRAP);
  printf("SIGURG : %d\n", SIGURG);
  printf("SIGVTALRM : %d\n", SIGVTALRM);
  printf("SIGXCPU : %d\n", SIGXCPU);
  printf("SIGXFSZ : %d\n", SIGXFSZ);
  printf("SIGIOT : %d\n", SIGIOT);
  printf("SIGSTKFLT : %d\n", SIGSTKFLT);
  printf("SIGIO : %d\n", SIGIO);
  printf("SIGCLD : %d\n", SIGCLD);
  printf("SIGPWR : %d\n", SIGPWR);
  printf("SIGWINCH : %d\n", SIGWINCH);
  printf("SIGUNSED : %d\n\n", SIGUNUSED);

  printf("SI_USR : %d\n", SI_USER);
  printf("SI_KERNEL : %d\n", SI_KERNEL);
  printf("SI_QUEUE : %d\n", SI_QUEUE);
  printf("SI_TIMER : %d\n", SI_TIMER);
  printf("SI_MESGQ : %d\n", SI_MESGQ);
  printf("SI_ASYNCIO : %d\n", SI_ASYNCIO);
  printf("SI_SIGIO : %d\n", SI_SIGIO);
  printf("SI_TKILL : %d\n", SI_TKILL);
  printf("ILL_ILLOPC : %d\n", ILL_ILLOPC);
  printf("ILL_ILLOPN : %d\n", ILL_ILLOPN);
  printf("ILL_ILADDR : %d\n", ILL_ILLADR);
  printf("ILL_ILLTRP : %d\n", ILL_ILLTRP);
  printf("ILL_PRVOPC : %d\n", ILL_PRVOPC);
  printf("ILL_PRVREG : %d\n", ILL_PRVREG);
  printf("ILL_COROC : %d\n", ILL_COPROC);
  printf("ILL_BADSTK : %d\n", ILL_BADSTK);
  printf("FPE_INTDIV : %d\n", FPE_INTDIV);
  printf("FPE_INTOVF : %d\n", FPE_INTOVF);
  printf("FPE_FLTDIV : %d\n", FPE_FLTDIV);
  printf("FPE_FLTOVF : %d\n", FPE_FLTOVF);
  printf("FPE_FLTUND : %d\n", FPE_FLTUND);
  printf("FPE_FLTRES : %d\n", FPE_FLTINV);
  printf("FPE_FLTSUB : %d\n", FPE_FLTSUB);
  printf("SEGV_MAPERR : %d\n", SEGV_MAPERR);
  printf("SEGV_ACCERR : %d\n", SEGV_ACCERR);
  printf("BUS_ADRALN : %d\n", BUS_ADRALN);
  printf("BUS_ADRERR : %d\n", BUS_ADRERR);
  printf("BUS_OBJERR : %d\n", BUS_OBJERR);
  printf("BUS_MCEERR_AR : %d\n", BUS_MCEERR_AR);
  printf("BUS_MCEERR_AO : %d\n", BUS_MCEERR_AO);
  printf("TRAP_BRKPT : %d\n", TRAP_BRKPT);
  printf("TRAP_TRACE : %d\n", TRAP_TRACE);
  printf("CLD_EXITED : %d\n", CLD_EXITED);
  printf("CLD_KILLED : %d\n", CLD_KILLED);
  printf("CLD_DUMPED : %d\n", CLD_DUMPED);
  printf("CLD_TRAPPED : %d\n", CLD_TRAPPED);
  printf("CLD_STOPPED : %d\n", CLD_STOPPED);
  printf("CLD_CONTINUED : %d\n", SEGV_MAPERR);
  printf("POLL_IN : %d\n", POLL_IN);
  printf("POLL_OUT : %d\n", POLL_OUT);
  printf("POLL_MSG : %d\n", POLL_MSG);
  printf("POLL_ERR : %d\n", POLL_ERR);
  printf("POLL_PRI : %d\n", POLL_PRI);
  printf("POLL_HUP : %d\n", POLL_HUP);

  return 0;
}
