/*
** my_putchar.c for  in /home/julienp36/poitre_j/DEVC/Jour01/my_putchar
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Mon Oct 16 10:40:01 2017 POITREAU Julien
** Last update Tue Nov  7 20:05:35 2017 POITREAU Julien
*/

#include <unistd.h>

void my_putchar(const char c)
{
write(1, &c, 1);
}
