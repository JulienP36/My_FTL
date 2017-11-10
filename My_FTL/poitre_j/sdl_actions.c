/*
** sdl_actions.c for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 16:18:23 2017 POITREAU Julien
** Last update Fri Nov 10 17:43:23 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

void		sdl_jump(t_sdl *sdl)
{
  int		counter;
  SDL_Rect	back;
  int		bgx;

  bgx = 0;
  counter = 0;
  while (counter < 1)
    {
      bgx -= 3;
      back.x = bgx;
      back.y = 0;
      SDL_BlitSurface(sdl->background, NULL, sdl->window, &back);
      back.x = bgx + 800;
      SDL_BlitSurface(sdl->background, NULL, sdl->window, &back);
      back.x = 0;
      back.y = 200;
      SDL_BlitSurface(sdl->ship, NULL, sdl->window, &back);
      if (bgx <= -800)
	{
	  bgx = 0;
	  counter++;
	}
      SDL_Flip(sdl->window);
    }
}

void		sdl_shoot(t_sdl *sdl)
{
  int		laserx;
  SDL_Rect	laser;

  laserx = 100;
  while (laserx < 700)
    {
      laserx += 5;
      laser.x = 0;
      laser.y = 0;
      SDL_BlitSurface(sdl->background, NULL, sdl->window, &laser);
      laser.x = laserx;
      laser.y = 281;
      SDL_BlitSurface(sdl->laser, NULL, sdl->window, &laser);
      laser.x = 0;
      laser.y = 200;
      SDL_BlitSurface(sdl->ship, NULL, sdl->window, &laser);
      laser.x = 600;
      SDL_BlitSurface(sdl->ennemyship, NULL, sdl->window, &laser);
      SDL_Flip(sdl->window);
    }
}

void		sdl_ennemy_shoot(t_sdl *sdl)
{
  int		laserx;
  SDL_Rect	laser;

  laserx = 600;
  while (laserx > 100)
    {
      laserx -= 5;
      laser.x = 0;
      laser.y = 0;
      SDL_BlitSurface(sdl->background, NULL, sdl->window, &laser);
      laser.x = laserx;
      laser.y = 281;
      SDL_BlitSurface(sdl->laser, NULL, sdl->window, &laser);
      laser.x = 0;
      laser.y = 200;
      SDL_BlitSurface(sdl->ship, NULL, sdl->window, &laser);
      laser.x = 600;
      SDL_BlitSurface(sdl->ennemyship, NULL, sdl->window, &laser);
      SDL_Flip(sdl->window);
    }
}
