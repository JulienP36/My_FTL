/*
** my_putstr.c for  in /home/julienp36/poitre_j/DEVC/Jour03/poitre_j/my_putstr
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Oct 18 09:22:48 2017 POITREAU Julien
** Last update Wed Oct 18 18:50:52 2017 POITREAU Julien
*/

void	my_putchar(char c);

void	my_putstr(char *str)
{
  int	counter;

  counter = 0;
  while (str[counter] != '\0')
    {
      my_putchar(str[counter]);
      counter++;
    }
}
