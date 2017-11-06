/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Sat Nov  4 17:59:09 2017 POITREAU Julien
*/

#include "ftl.h"

t_ship	*create_ship();
int	add_weapon_to_ship(t_ship p_ship);

int		main()
{
  t_ship	*ptr_ship;
  ptr_ship = create_ship();
  add_weapon_to_ship(*ptr_ship);
  
  return (0);
}
