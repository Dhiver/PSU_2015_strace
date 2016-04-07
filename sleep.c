#include <stdio.h>
#include <unistd.h>

int	main(void)
{
  printf("%d\n", getpid());
  sleep(300);
  return 0;
}
