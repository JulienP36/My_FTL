/*
** my_strdup.c for  in /home/julienp36/poitre_j/DEVC/Jour07/poitre_j/my_strdup
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Mon Oct 23 11:01:24 2017 POITREAU Julien
** Last update Tue Nov  7 10:22:33 2017 POITREAU Julien
*/

#include <stdio.h>
#include <stdlib.h>

void	my_putchar(char c);

int	my_strlen(char *str);

char	*my_strdup(char *str)
{
  char	*new_str;
  int	counter;

  counter = 0;
  new_str = NULL;
  new_str = malloc((my_strlen(str) + 1) * sizeof (char));
  while (str[counter] != '\0')
    {
      new_str[counter] = str[counter];
      counter++;
    }
  new_str[counter] = '\0';
  return (new_str);
}
