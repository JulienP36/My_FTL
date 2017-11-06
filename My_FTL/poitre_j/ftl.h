/*
** ftl.h for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:11:54 2017 POITREAU Julien
** Last update Mon Nov  6 20:16:59 2017 POITREAU Julien
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

typedef struct	s_weapon
{
  char*		system_state;
  int		damage;
} t_weapon;

typedef struct	s_ftl_drive
{
  char*		system_state;
  int		energy;
} t_ftl_drive;

typedef struct	s_navigation_tools
{
  char*		system_state;
  int		sector;
  int		evade;
} t_navigation_tools;

typedef struct	s_freight t_freight;
struct		s_freight
{
  char		*item;
  t_freight	*next;
  t_freight	*prev;
};

typedef struct	s_container
{
  t_freight	*first;
  t_freight	*last;
  int		nb_elem;
} t_container;

typedef struct		s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*nav_tools;
  t_container		*container;
} t_ship;

#endif
