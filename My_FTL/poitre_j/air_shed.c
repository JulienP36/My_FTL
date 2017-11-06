/*
** air_shed.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:37:24 2017 POITREAU Julien
** Last update Sat Nov  4 17:57:25 2017 POITREAU Julien
*/

#include "ftl.h"

t_ship		*create_ship()
{
  my_putstr("construction du vaisseau en cours...\n");
  t_ship	*p_ship;

  p_ship = malloc(sizeof(int));
  if (p_ship == NULL)
    {
      my_putstr("le vaisseau n'a pas pu etre construit ");
      my_putstr("par manque de materiaux\n");
      return (0);
    }
  else
    {
      my_putstr("amelioration du vaisseau termine!\n");
      p_ship->hull = 50;
      p_ship->ptr_weapon = NULL;
    }
  return (p_ship);
}

int	add_weapon_to_ship(t_ship *p_ship)
{
  my_putstr("ajout des armes en cours...\n");
  t_weapon	*p_weapon;

  p_weapon = malloc(sizeof(int));
  if (p_weapon == NULL)
    {
      my_putstr("votre vaisseau a explose quand vous avez ");
      my_putstr("tente d'ajouter les armes\n");
      return (0);
    }
  else
    {
      my_putstr("les armes ont ete ajoutes avec succes!\n");
      p_weapon->damage = 10;
      p_weapon->system_state = my_strdup("online");
      p_ship->ptr_weapon = p_weapon;
    }
  return (1);
}
