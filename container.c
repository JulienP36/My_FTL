/*
** container.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Mon Nov  6 20:07:28 2017 POITREAU Julien
** Last update Tue Nov  7 10:10:09 2017 POITREAU Julien
*/

#include "ftl.h"

int		add_container_to_ship(t_ship *ptr_ship)
{
  my_putstr("ajout du container en cours...\n");
  t_container	*p_container;

  p_container = malloc(sizeof(t_container));
  if (p_container == NULL)
    {
      my_putstr("votre vaisseau a explose lorsque vous avez ");
      my_putstr("pose le container\n");
      return (0);
    }
  else
    {
      my_putstr("le container a ete ajoute avec succes!\n");
      p_container->first = NULL;
      p_container->last = NULL;
      p_container->nb_elem = 0;
      ptr_ship->container = p_container;
    }
  return (1);
}

void	add_freight_to_container(t_ship *ptr_ship, t_freight *ptr_freight)
{
  if (ptr_freight != NULL)
    {
      ptr_freight->next = NULL;
      if (ptr_ship->container->last == NULL)
	{
	  ptr_freight->prev = NULL;
	  ptr_ship->container->first = ptr_freight;
	  ptr_ship->container->last = ptr_freight;
	}
      else
	{
	  ptr_ship->container->last->next = ptr_freight;
	  ptr_freight->prev = ptr_ship->container->last;
	  ptr_ship->container->last = ptr_ship->container->last->next;
	}
      ptr_ship->container->nb_elem++;
    }
  else
    {
      my_putstr("DEBUG: Erreur: le pointeur reçu est invalide\n");
    }
}

void	del_freight_from_container(t_ship *ptr_ship, t_freight *ptr_freight)
{
  if (ptr_freight != NULL)
    {
      if ((ptr_ship->container->last == ptr_freight) && (ptr_ship->container->first == ptr_freight))
	{
	  ptr_ship->container->first = NULL;
	  ptr_ship->container->last = NULL;
	}
      else
	{
	  if (ptr_ship->container->first == ptr_freight)
	    {
	      ptr_freight->next->prev = NULL;
	      ptr_ship->container->first = ptr_freight->next;
	    }
	  else if (ptr_ship->container->last == ptr_freight)
	    {
	      ptr_freight->prev->next = NULL;
	      ptr_ship->container->last = ptr_freight->prev;
	    }
	  else
	    {
	      ptr_freight->prev->next = ptr_freight->next;
	      ptr_freight->next->prev = ptr_freight->prev;
	    }
	}
      ptr_ship->container->nb_elem--;
      free(ptr_freight);
    }
  else
    {
      my_putstr("DEBUG: Erreur: le pointeur reçu est invalide\n");
    }
}

void	get_bonus(t_ship *ptr_ship)
{
  t_freight	*current;

  current = ptr_ship->container->first;
  while (current != NULL)
    {
      if (my_strcmp(current->item, "attackbonus") == 0)
	{
	  ptr_ship->weapon->damage += 5;
	}
      else if (my_strcmp(current->item, "evadebonus") == 0)
	{
	  ptr_ship->nav_tools->evade += 3;
	}
      else if (my_strcmp(current->item, "energy") == 0)
	{
	  ptr_ship->ftl_drive->energy += 1;
	}
      del_freight_from_container(ptr_ship, current);
      current = ptr_ship->container->first;
    }
}
