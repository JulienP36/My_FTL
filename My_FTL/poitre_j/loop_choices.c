/*
** loop_choices.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:50:01 2017 POITREAU Julien
** Last update Wed Nov  8 10:17:03 2017 POITREAU Julien
*/

#include "ftl.h"

void	basic_display(t_ship *ptr_ship)
{
  my_putstr("||__SECTOR_");
  my_put_nbr(ptr_ship->nav_tools->sector);
  my_putstr("__||");
  my_putstr("\n\n>INPUT~> ");
}

void	stats_display(t_ship *ptr_ship)
{
  my_putstr("\n|| Hull : ");
  my_put_nbr(ptr_ship->hull);
  my_putstr("\n|| Weapons damage : ");
  my_put_nbr(ptr_ship->weapon->damage);
  my_putstr("\n|| Energy : ");
  my_put_nbr(ptr_ship->ftl_drive->energy);
  my_putstr("\n|| Sector : ");
  my_put_nbr(ptr_ship->nav_tools->sector);
  my_putstr("\n|| Evade : ");
  my_put_nbr(ptr_ship->nav_tools->evade);
  my_putchar('\n');
}
