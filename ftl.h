/*
** ftl.h for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:11:54 2017 POITREAU Julien
** Last update Sat Nov  4 16:48:45 2017 POITREAU Julien
*/

#ifndef FTL_H
#define FTL_H

#include <stdio.h>
#include <stdlib.h>

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int n);
char	*readLine();

typedef struct s_ship t_ship;
struct s_ship
{
  int hull;
};

#endif
