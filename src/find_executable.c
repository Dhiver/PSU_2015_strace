/*
** find_executable.c for strace in /home/work/work/projects/PSU_2015_strace_doc/PSU_2015_strace/src
**
** Made by Bastien DHIVER
** Login   <dhiver_b@epitech.net>
**
** Started on  Tue Apr 05 10:02:23 2016 Bastien DHIVER
** Last update Tue Apr  5 14:40:48 2016 florian videau
*/

#include <limits.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include "strace.h"

char		*loop(char *name, char *path, size_t len)
{
  char		*sav_path;
  size_t	len_p;
  char		buf[PATH_MAX];

  while (1)
    {
      bzero(buf, PATH_MAX);
      sav_path = path;
      while (*path != 0 && *path != ':')
	path++;
      len_p = (sav_path == path && (sav_path = ".")) ? 1 : path - sav_path;
      if (len_p + len + 2 > sizeof(buf))
	continue;
      memcpy(buf, sav_path, len_p);
      buf[len_p] = '/';
      memcpy(buf + len_p + 1, name, len);
      buf[len_p + len + 1] = '\0';
      if (access(buf, F_OK) == 0 && access(buf, X_OK) == 0)
	return (strdup(buf));
      if (*path++ != ':')
	break;
    }
  return (NULL);
}

char	*find_executable(char *name)
{
  char	*path;

  if (!name || name[0] == '\0')
    return (NULL);
  if (strchr(name, '/'))
    return (name);
  if ((path = getenv("PATH")) == NULL)
    path = DEFAULT_PATH;
  return (loop(name, path, strlen(name)));
}
