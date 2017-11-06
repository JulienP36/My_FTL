/*
** my_put_nbr.c for  in /home/julienp36/poitre_j/DEVC/Jour05-06/poitre_j/my_put_nbr
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Fri Oct 20 09:27:30 2017 POITREAU Julien
** Last update Sat Oct 21 09:47:33 2017 POITREAU Julien
*/

void	my_putchar(char c);

void	my_put_nbr(int n)
{
  int	counter;
  
  counter = 1;
  if (n < 0)
    {
      my_putchar('-');
      n *= -1;
    }
  while ((n / counter) >= 10)
    {
      counter *= 10;
    }
  while (counter > 0)
    {
      my_putchar((n / counter) % 10 + '0');
      counter /= 10;
    }
}
