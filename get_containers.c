/*
** get_containers.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Thu Nov  9 10:01:46 2017 POITREAU Julien
** Last update Thu Nov  9 10:52:01 2017 POITREAU Julien
*/

#include	"ftl.h"

void		get_containers(t_ship *ptr_ship)
{
  int		counter;
  t_freight	*cur_item;

  counter = 0;
  srand(time(NULL));
  my_putstr_color("cyan", "\n[System]: Resultat de detection:");
  while (counter < 10)
    {
      cur_item = create_freight();
      add_freight_to_container(ptr_ship, cur_item);
      counter++;
    }
}
