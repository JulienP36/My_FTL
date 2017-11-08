/*
** system_control.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 09:46:45 2017 POITREAU Julien
** Last update Wed Nov  8 10:16:17 2017 POITREAU Julien
*/

#include "ftl.h"

void	ftl_drive_system_check(t_ship *ptr_ship)
{
  my_putstr("verification du reacteur en cours...\n");
  if (my_strcmp(ptr_ship->ftl_drive->system_state, "online") == 0)
    my_putstr_color("green", "reacteur OK!\n");
  else
    my_putstr_color("red", "reacteur hors service!\n");
}

void	navigation_tools_system_check(t_ship *ptr_ship)
{
  my_putstr("verification du systeme de navigation en cours...\n");
  if (my_strcmp(ptr_ship->nav_tools->system_state, "online")  == 0)
    my_putstr_color("green", "systeme de navigation OK!\n");
  else
    my_putstr_color("red", "systeme de navigation hors service!\n");
}

void	weapon_system_check(t_ship *ptr_ship)
{
  my_putstr("verification du systeme d'armement en cours...\n");
  if (my_strcmp(ptr_ship->weapon->system_state, "online")  == 0)
    my_putstr_color("green", "systeme d'armement OK!\n");
  else
    my_putstr_color("red", "systeme d'armement hors service!\n");
}

void	system_control(t_ship *ptr_ship)
{
  ftl_drive_system_check(ptr_ship);
  navigation_tools_system_check(ptr_ship);
  weapon_system_check(ptr_ship);
}
