/*
** air_shed.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:37:24 2017 POITREAU Julien
** Last update Sat Nov  4 16:34:21 2017 POITREAU Julien
*/

#include "ftl.h"

t_ship		*create_ship()
{
  t_ship	*p_hull;

  p_hull = malloc(sizeof(int));
  my_putstr("construction du vaisseau en cours...\n");
  if (p_hull == NULL)
    {
      my_putstr("le vaisseau n'a pas pu etre construit ");
      my_putstr("par manque de materiaux\n");
      return (0);
    }
  else
    {
      my_putstr("amelioration du vaisseau termine!\n");
      //*p_hull = 50;
    }
  return (p_hull);
}
