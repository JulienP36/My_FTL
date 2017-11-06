/*
** my_strdup.c for  in /home/julienp36/poitre_j/DEVC/Jour07/poitre_j/my_strdup
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Mon Oct 23 11:01:24 2017 POITREAU Julien
** Last update Sat Nov  4 18:50:06 2017 POITREAU Julien
*/

#include <stdio.h>
#include <stdlib.h>

void	my_putchar(char c);

char	*my_strdup(char *str)
{
  char	*new_str;
  int	counter;

  counter = 0;
  new_str = malloc(sizeof (str));
  while (str[counter] != '\0')
    {
      new_str[counter] = str[counter];
      counter++;
    }
  new_str[counter] = '\0';
  return (new_str);
}
