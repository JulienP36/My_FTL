/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Thu Nov  9 11:17:58 2017 POITREAU Julien
*/

#include	"ftl.h"

void		free_all(t_ship *ptr_ship);

void		add_things_to_ship(t_ship *p_ship)
{
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
}

void		game_loop(t_ship *ptr_ship)
{
  char		*choice;

  while (ptr_ship->nav_tools->sector < 10)
    {
      my_putstr_color("clear", "");
      basic_display(ptr_ship);
      choice = readLine();
      command_check(ptr_ship, choice);
      free(choice);
      my_putstr("\nAppuyez sur ENTER pour continuer...");
      choice = readLine();
      free(choice);
      if (ptr_ship->nav_tools->sector >= 10)
	{
	  my_putstr_color("cyan", "\nVous etes arrives a destination!\n");
	  my_putstr_color("green", "\nVous avez gagne!\n\n");
	}
      else if (ptr_ship->hull <= 0)
	{
	  my_putstr_color("yellow", "\nVotre vaisseau est detruit!\n");
	  my_putstr_color("red", "\nVous avez perdu!\n\n");
	  ptr_ship->nav_tools->sector = 10;
	}
      else if (ptr_ship->ftl_drive->energy <= 0)
	{
	  my_putstr_color("yellow", "\nVotre vaisseau n'as plus d'energie!\n");
	  my_putstr_color("red", "\nVous avez perdu!\n\n");
	  ptr_ship->nav_tools->sector = 10;
	}
    }
}

int		main()
{
  t_ship	*ptr_ship;
  char		*pause;

  ptr_ship = create_ship();
  add_things_to_ship(ptr_ship);
  add_misc(ptr_ship);
  system_control(ptr_ship);
  my_putstr("\nAppuyez sur ENTER pour continuer...\n");
  pause = readLine();
  free(pause);
  game_loop(ptr_ship);
  free_all(ptr_ship);
  return (0);
}

void		free_all(t_ship *ptr_ship)
{
  ptr_ship->fight->engaged = 0;
  get_bonus(ptr_ship);
  free(ptr_ship->weapon->system_state);
  free(ptr_ship->ftl_drive->system_state);
  free(ptr_ship->nav_tools->system_state);
  free(ptr_ship->weapon);
  free(ptr_ship->ftl_drive);
  free(ptr_ship->nav_tools);
  free(ptr_ship->ennemy);
  free(ptr_ship->next_ennemy);
  free(ptr_ship->fight);
  free(ptr_ship->container);
  free(ptr_ship);
}
