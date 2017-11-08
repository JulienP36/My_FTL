/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Wed Nov  8 10:27:34 2017 POITREAU Julien
*/

#include "ftl.h"

void	add_things_to_ship(t_ship *p_ship)
{
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
}

void	game_loop(t_ship *ptr_ship)
{
  char	*choice;

  while (ptr_ship->nav_tools->sector <= 10)
    {
      system("clear");
      basic_display(ptr_ship);
      choice = readLine();
      command_check(ptr_ship, choice);
      my_putstr("\nAppuyez sur ENTER pour continuer...");
      readLine();
    }
}

int		main()
{
  t_ship	*ptr_ship;
  ptr_ship = malloc(sizeof(t_ship));
  ptr_ship = create_ship();
  add_things_to_ship(ptr_ship);
  system_control(ptr_ship);
  my_putstr("\nAppuyez sur ENTER pour continuer...\n");
  readLine();
  game_loop(ptr_ship);
  free(ptr_ship);
  return (0);
}
