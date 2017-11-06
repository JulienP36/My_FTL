/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Mon Nov  6 20:14:01 2017 POITREAU Julien
*/

#include "ftl.h"

t_ship	*create_ship();
int	add_weapon_to_ship(t_ship *p_ship);
int	add_ftl_drive_to_ship(t_ship *p_ship);
int	add_navigation_tools_to_ship(t_ship *p_ship);
int	add_container_to_ship(t_ship *p_ship);

void	add_things_to_ship(t_ship *p_ship)
{
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
}

int		main()
{
  t_ship	*ptr_ship;
  ptr_ship = malloc(sizeof(t_ship));
  ptr_ship = create_ship();
  add_things_to_ship(ptr_ship);
  free(ptr_ship);
  return (0);
}
