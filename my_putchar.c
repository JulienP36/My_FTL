/*
** my_putchar.c for  in /home/julienp36/poitre_j/DEVC/Jour01/my_putchar
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Mon Oct 16 10:40:01 2017 POITREAU Julien
** Last update Mon Oct 16 12:21:08 2017 POITREAU Julien
*/

#include <unistd.h>

void my_putchar(char c)
{
write(1, &c, 1);
}
