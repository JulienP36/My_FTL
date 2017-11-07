/*
** my_strlen.c for  in /home/julienp36/poitre_j/DEVC/Jour03/poitre_j/my_strlen
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Oct 18 09:13:33 2017 POITREAU Julien
** Last update Wed Oct 18 09:24:01 2017 POITREAU Julien
*/

void	my_putchar(char c);

int	my_strlen(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      counter++;
    }
  return counter;
}
