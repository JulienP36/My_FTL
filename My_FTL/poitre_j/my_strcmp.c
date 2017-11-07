/*
** my_strcmp.c for  in /home/julienp36/poitre_j/DEVC/Jour04/poitre_j/my_strcmp
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Thu Oct 19 14:32:36 2017 POITREAU Julien
** Last update Thu Oct 19 22:11:18 2017 POITREAU Julien
*/

void	my_putchar(char c);

int	my_strcmp(char *s1, char *s2)
{
  int	counter;

  counter = 0;
  while (s1[counter] != '\0')
    {
      if (s1[counter] < s2[counter])
	{
	  return (-1);
	}
      else if (s1[counter] > s2[counter])
	{
	  return (1);
	}
      counter++;
    }
  if ((s1[counter] == '\0') && (s2[counter] != '\0'))
    {
      return (-1);
    }
  return (0);
}
