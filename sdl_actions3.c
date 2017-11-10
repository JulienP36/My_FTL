/*
** sdl_actions3.c for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 22:27:04 2017 POITREAU Julien
** Last update Fri Nov 10 22:30:32 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

void		sdl_heal_me(t_sdl *sdl)
{
  SDL_Rect	heal;
  SDL_Rect	pos;
  int		counter;

  counter = 0;
  while (counter < 9)
    {
      heal.x = counter * 100; 
      heal.y = 0;
      heal.w = 100;
      heal.h = 100;
      counter++;
      pos.x = 0;
      pos.y = 0;
      SDL_BlitSurface(sdl->background, NULL, sdl->window, &pos);
      pos.y = 200;
      SDL_BlitSurface(sdl->ship, NULL, sdl->window, &pos);
      pos.x = 75;
      pos.y = 250;
      SDL_BlitSurface(sdl->heal, &heal, sdl->window, &pos);
      SDL_Flip(sdl->window);
      SDL_Delay(50);
    }
}
