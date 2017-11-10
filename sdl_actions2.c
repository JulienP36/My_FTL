/*
** sdl_actions2.c for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 20:27:46 2017 POITREAU Julien
** Last update Fri Nov 10 21:21:16 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

void		sdl_explosion_me(t_sdl *sdl)
{
  SDL_Rect	boom;
  SDL_Rect	pos;
  int		counter;

  counter = 0;
  while (counter < 9)
    {
      boom.x = counter * 100; 
      boom.y = 0;
      boom.w = 100;
      boom.h = 100;
      counter++;
      pos.x = 0;
      pos.y = 0;
      SDL_BlitSurface(sdl->background, NULL, sdl->window, &pos);
      pos.x = 0;
      pos.y = 200;
      SDL_BlitSurface(sdl->ship, NULL, sdl->window, &pos);
      pos.x = 600;
      SDL_BlitSurface(sdl->ennemyship, NULL, sdl->window, &pos);
      pos.x = 75;
      pos.y = 250;
      SDL_BlitSurface(sdl->boom, &boom, sdl->window, &pos);
      SDL_Flip(sdl->window);
      SDL_Delay(50);
    }
}

void		sdl_player_death(t_ship *ptr_ship, t_sdl *sdl)
{
  SDL_Rect	pos;

  if (my_strcmp(ptr_ship->nav_tools->system_state, "online") == 0)
    sdl->nav_tools = IMG_Load("nav_tools_on.png");
  if (my_strcmp(ptr_ship->ftl_drive->system_state, "online") == 0)
    sdl->ftl_drive = IMG_Load("ftl_drive_on.png");
  if (my_strcmp(ptr_ship->weapon->system_state, "online") == 0)
    sdl->weapons = IMG_Load("weapon_on.png");
  pos.x = 0;
  pos.y = 0;
  SDL_BlitSurface(sdl->background, NULL, sdl->window, &pos);
  pos.x = 600;
  pos.y = 200;
  SDL_BlitSurface(sdl->ennemyship, NULL, sdl->window, &pos);
  pos.x = 10;
  pos.y = 500;
  SDL_BlitSurface(sdl->ftl_drive, NULL, sdl->window, &pos);
  pos.x = 84;
  SDL_BlitSurface(sdl->nav_tools, NULL, sdl->window, &pos);
  pos.x = 158;
  SDL_BlitSurface(sdl->weapons, NULL, sdl->window, &pos);
}

void		game_over(t_ship *ptr_ship, t_sdl *sdl)
{
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
      sdl_explosion_me(sdl);
      sdl_player_death(ptr_ship, sdl);
      SDL_Flip(sdl->window);
    }
  else if (ptr_ship->ftl_drive->energy <= 0)
    {
      my_putstr_color("yellow", "\nVotre vaisseau n'as plus d'energie!\n");
      my_putstr_color("red", "\nVous avez perdu!\n\n");
      ptr_ship->nav_tools->sector = 10;
    }
}
