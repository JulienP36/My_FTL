/*
** air_shed.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:37:24 2017 POITREAU Julien
** Last update Fri Nov 10 13:28:19 2017 POITREAU Julien
*/

#include "ftl.h"

t_ship		*create_ship()
{
  my_putstr("construction du vaisseau en cours...\n");
  t_ship	*p_ship;

  p_ship = malloc(sizeof(t_ship));
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
      p_ship->weapon = NULL;
      p_ship->ftl_drive = NULL;
      p_ship->nav_tools = NULL;
      p_ship->container = NULL;
    }
  return (p_ship);
}

int	add_weapon_to_ship(t_ship *ptr_ship)
{
  my_putstr("ajout des armes en cours...\n");
  t_weapon	*p_weapon;

  p_weapon = malloc(sizeof(t_weapon));
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
      ptr_ship->weapon = p_weapon;
    }
  return (1);
}

int	add_ftl_drive_to_ship(t_ship *ptr_ship)
{
  my_putstr("ajout du reacteur en cours...\n");
  t_ftl_drive	*p_ftl_drive;

  p_ftl_drive = malloc(sizeof(t_ftl_drive));
  if (p_ftl_drive == NULL)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez ");
      my_putstr("pose le reacteur\n");
      return (0);
    }
  else
    {
      my_putstr("le reacteur a ete ajoute avec succes!\n");
      p_ftl_drive->energy = 10;
      p_ftl_drive->system_state = my_strdup("online");
      ptr_ship->ftl_drive = p_ftl_drive;
    }
  return (1);
}

int	add_navigation_tools_to_ship(t_ship *ptr_ship)
{
  my_putstr("ajout des outils de navigation...\n");
  t_navigation_tools	*p_navigation_tools;

  p_navigation_tools = malloc(sizeof(t_navigation_tools));
  if (p_navigation_tools == NULL)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez ");
      my_putstr("pose les outils de navigation\n");
      return (0);
    }
  else
    {
      my_putstr("les outils de navigation ont ete ajoute avec succes!\n");
      p_navigation_tools->sector = 0;
      p_navigation_tools->evade = 25;
      p_navigation_tools->system_state = my_strdup("online");
      ptr_ship->nav_tools = p_navigation_tools;
    }
  return (1);
}

int		add_misc(t_ship *ptr_ship)
{
  t_ennemy	*p_ennemy;
  t_next_ennemy *p_next_ennemy;;
  t_fight	*p_fight;

  p_ennemy = malloc(sizeof(t_ennemy));
  p_next_ennemy = malloc(sizeof(t_next_ennemy));
  p_fight = malloc(sizeof(t_fight));
  p_ennemy->damage = 10;
  p_ennemy->health = 20;
  p_next_ennemy->damage = 10;
  p_next_ennemy->health = 20;
  p_fight->engaged = 0;
  p_fight->turn_done = 0;
  ptr_ship->fight = p_fight;
  ptr_ship->ennemy = p_ennemy;
  ptr_ship->next_ennemy = p_next_ennemy;
  ptr_ship->sdl = NULL;
  return (1);
}
