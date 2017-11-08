/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Tue Nov  7 21:55:18 2017 POITREAU Julien
*/

#include "ftl.h"

void	add_things_to_ship(t_ship *p_ship)
{
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
}

void	game_test(t_ship *ptr_ship)
{
  int	counter;
  char	*choice;

  counter = 0;
  while (counter < 10)
    {
      system("clear");
      my_putstr("||__SECTOR_");
      my_put_nbr(counter);
      my_putstr("__||");
      my_putstr("\n\n|| Hull : ");
      my_put_nbr(ptr_ship->hull);
      my_putstr("\n\nWEAPONS STATE : ");
      if (my_strcmp(ptr_ship->weapon->system_state, "online") == 0)
	my_putstr_color("green", ptr_ship->weapon->system_state);
      else
	my_putstr_color("red", ptr_ship->weapon->system_state);
      my_putstr("\n|| Weapons damage : ");
      my_put_nbr(ptr_ship->weapon->damage);      
      my_putstr("\n\nFTL_DRIVE STATE : ");
      if (my_strcmp(ptr_ship->ftl_drive->system_state, "online") == 0)
	my_putstr_color("green", ptr_ship->ftl_drive->system_state);
      else
	my_putstr_color("red", ptr_ship->ftl_drive->system_state);
      my_putstr("\n|| Energy : ");
      my_put_nbr(ptr_ship->ftl_drive->energy);
      my_putstr("\n\nNAVIGATION TOOLS STATE : ");
      if (my_strcmp(ptr_ship->ftl_drive->system_state, "online") == 0)
	my_putstr_color("green", ptr_ship->nav_tools->system_state);
      else
	my_putstr_color("red", ptr_ship->nav_tools->system_state);
      my_putstr("\n|| Sector : ");
      my_put_nbr(ptr_ship->nav_tools->sector);
      my_putstr("\n|| Evade : ");
      my_put_nbr(ptr_ship->nav_tools->evade);
      my_putstr("\n\n>INPUT~> ");
      choice = readLine();
      my_putstr(choice);
      counter++;
      ptr_ship->nav_tools->sector++;
    }
}

int		main()
{
  t_ship	*ptr_ship;
  ptr_ship = malloc(sizeof(t_ship));
  ptr_ship = create_ship();
  add_things_to_ship(ptr_ship);
  system_control(ptr_ship);
  //system_repair(ptr_ship);
  my_putstr("\nAppuyez sur ENTER pour continuer... svp ...");
  readLine();
  game_test(ptr_ship);
  free(ptr_ship);
  return (0);
}
