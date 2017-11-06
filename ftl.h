/*
** ftl.h for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:11:54 2017 POITREAU Julien
** Last update Sat Nov  4 17:38:03 2017 POITREAU Julien
*/

#ifndef FTL_H
#define FTL_H

#include <stdio.h>
#include <stdlib.h>

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int n);
char	*my_strdup(char *str);
char	*readLine();

typedef struct s_ship t_ship;
typedef struct s_weapon t_weapon;

struct		s_ship
{
  int		hull;
  t_weapon	*ptr_weapon;
};

struct	s_weapon
{
  char	*system_state;
  int	damage;
};

#endif
