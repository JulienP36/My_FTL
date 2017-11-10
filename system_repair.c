/*
** system_repair.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Tue Nov  7 11:14:56 2017 POITREAU Julien
** Last update Fri Nov 10 22:42:42 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

static const t_repair_command	repair_command[] =
  {
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {NULL, NULL}
  };

void	ftl_drive_system_repair(t_ship *ptr_ship)
{
  char	*state;

  my_putstr("reparation du reacteur en cours...\n");
  free(ptr_ship->ftl_drive->system_state);
  state = my_strdup("online");
  if (state != NULL)
    {
      my_putstr("reparation termine! systeme reacteur OK!\n");
      ptr_ship->ftl_drive->system_state = state;
    }
  else
    {
      my_putstr("les reparations du reacteur ont echoue\n");
    }
}

void	navigation_tools_system_repair(t_ship *ptr_ship)
{
  char	*state;

  my_putstr("reparation des outils de navigation en cours...\n");
  free(ptr_ship->nav_tools->system_state);
  state = my_strdup("online");
  if (state != NULL)
    {
      my_putstr("reparation termine! systeme de navigation OK!\n");
      ptr_ship->nav_tools->system_state = state;
    }
  else
    {
      my_putstr("les reparations des outils de navigation ont echoue\n");
    }
}

void	weapon_system_repair(t_ship *ptr_ship)
{
  char	*state;

  my_putstr("reparation du systeme d'armement en cours...\n");
  free(ptr_ship->weapon->system_state);
  state = my_strdup("online");
  if (state != NULL)
    {
      my_putstr("reparation termine! systeme d'armement OK!\n");
      ptr_ship->weapon->system_state = state;
    }
  else
    {
      my_putstr("les reparations du systeme d'armement ont echoue\n");
    }
}

void	system_repair_check(t_ship *ptr_ship, char *command, t_sdl *sdl)
{
  int	counter;
  int	is_correct;

  is_correct = 0;
  counter = 0;
  while (repair_command[counter].str != NULL)
    {
      if (my_strcmp(repair_command[counter].str, command) == 0)
	{
	  repair_command[counter].ptr(ptr_ship);
	  is_correct = 1;
	  sdl_heal_me(sdl);
	}
      counter++;
    }
  if (is_correct == 0)
    {
      my_putstr("[SYSTEM FAILURE] : commande inconnue\n");
    }
}

void	system_repair(t_ship *ptr_ship, t_sdl *sdl)
{
  char	*command;

  my_putstr("repair_system~>");
  command = readLine();
  if (command != NULL)
    {
      system_repair_check(ptr_ship, command, sdl);
    }
  else
    {
      my_putstr("[SYSTEM FAILURE] : le lecteur de commande est bloque\n");
    }
}
