/*
** main.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 16:37:18 2017 POITREAU Julien
** Last update Fri Nov 10 13:06:11 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

void		free_all(t_ship *ptr_ship);

void		add_things_to_ship(t_ship *p_ship)
{
  add_weapon_to_ship(p_ship);
  add_ftl_drive_to_ship(p_ship);
  add_navigation_tools_to_ship(p_ship);
  add_container_to_ship(p_ship);
}

void		game_loop(t_ship *ptr_ship, t_sdl *sdl)
{
  char		*choice;

  while (ptr_ship->nav_tools->sector < 10)
    {
      my_putstr_color("clear", "");
      basic_display(ptr_ship, sdl);
      choice = readLine();
      command_check(ptr_ship, choice, sdl);
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

t_sdl		*start_sdl()
{
  t_sdl		*sdl;
  SDL_Rect	pos;

  sdl = malloc(sizeof(t_sdl));
  sdl->pos_ship.x = 0;
  sdl->pos_ship.y = 200;
  sdl->pos_ennemyship.x = 600;
  sdl->pos_ennemyship.y = 200;
  sdl->back.x = 0;
  sdl->back.y = 0;
  sdl->pos_ftl_drive.x = 10;
  sdl->pos_ftl_drive.y = 500;
  sdl->pos_nav_tools.x = 84;
  sdl->pos_nav_tools.y = 500;
  sdl->pos_weapons.x = 158;
  sdl->pos_weapons.y = 500;
  sdl->weapons = IMG_Load("weapon_on.png");
  sdl->nav_tools = IMG_Load("nav_tools_on.png");
  sdl->ftl_drive = IMG_Load("ftl_drive_on.png");
  sdl->ennemyship = IMG_Load("EnnemyShip.png");
  sdl->ship = IMG_Load("Ship.png");
  sdl->background = IMG_Load("SpaceView.png"); 
  SDL_Init(SDL_INIT_VIDEO);
  sdl->window = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
  SDL_WM_SetCaption("My_FTL : Space Kiwi Edition", NULL);

  pos.x = sdl->back.x;
  pos.y = sdl->back.y;
  SDL_BlitSurface(sdl->background, NULL, sdl->window, &pos);
  
  SDL_Flip(sdl->window);
  return (sdl);
}

int		main()
{
  t_ship	*ptr_ship;
  t_sdl		*sdl;
  char		*pause;

  ptr_ship = create_ship();
  sdl = start_sdl();
  add_things_to_ship(ptr_ship);
  add_misc(ptr_ship);
  system_control(ptr_ship);
  my_putstr("\nAppuyez sur ENTER pour continuer...\n");
  pause = readLine();
  free(pause);
  game_loop(ptr_ship, sdl);
  free_all(ptr_ship);
  return (0);
}

void		free_all(t_ship *ptr_ship)
{
  SDL_Quit();
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
