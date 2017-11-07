/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Tue Nov  7 19:44:38 2017 POITREAU Julien
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
      my_putstr("\nHULL : ");
      my_put_nbr(ptr_ship->hull);
      //my_putstr("\nHULL : ");
      //my_put_nbr(ptr_ship->hull);
      my_putstr("\n\n>INPUT~> ");
      choice = readLine();
      my_putstr(choice);
      counter++;
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
