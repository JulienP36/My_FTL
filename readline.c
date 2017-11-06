/*
  Cette fonction permet de récupérer une ligne
  de moins de 50 caractères sur l'entrée standard.
  La fonction ne prend pas de paramètres et renvoi une chaîne
  de caractères allouée.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

char		*readLine()
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}
