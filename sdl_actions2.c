/*
** sdl_actions2.c for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 20:27:46 2017 POITREAU Julien
** Last update Fri Nov 10 20:29:47 2017 POITREAU Julien
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
      pos.x = 50;
      pos.y = 250;
      SDL_BlitSurface(sdl->boom, &boom, sdl->window, &pos);
      SDL_Flip(sdl->window);
      SDL_Delay(50);
    }
}
