/*
** ftl.h for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:11:54 2017 POITREAU Julien
** Last update Tue Nov  7 14:08:43 2017 POITREAU Julien
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
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);

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

typedef struct	s_repair_command
{
  char		*str;
  void		(*ptr)(t_ship* p_ship);
} t_repair_command;

t_ship	*create_ship();
int	add_weapon_to_ship(t_ship *ptr_ship);
int	add_ftl_drive_to_ship(t_ship *ptr_ship);
int	add_navigation_tools_to_ship(t_ship *ptr_ship);
int	add_container_to_ship(t_ship *ptr_ship);
void	system_control(t_ship *ptr_ship);
void	ftl_drive_system_repair(t_ship *ptr_ship);
void	navigation_tools_system_repair(t_ship *ptr_ship);
void	weapon_system_repair(t_ship *ptr_ship);
void	system_repair(t_ship *ptr_ship);

#endif
