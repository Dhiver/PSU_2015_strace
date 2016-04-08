#include <signal.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
  (void) ac;

  sigqueue(atoi(av[1]), SIGSEGV, (union sigval) NULL);
  return 0;
}
