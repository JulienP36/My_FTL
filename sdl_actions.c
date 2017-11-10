/*
** sdl_actions.c for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Fri Nov 10 16:18:23 2017 POITREAU Julien
** Last update Fri Nov 10 20:31:18 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

void		sdl_explosion(t_sdl *sdl)
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
      pos.y = 250;
      SDL_BlitSurface(sdl->boom, &boom, sdl->window, &pos);
      SDL_Flip(sdl->window);
      SDL_Delay(50);
    }
}

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
  sdl_explosion(sdl);
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
  sdl_explosion_me(sdl);
}

void		sdl_ennemy_shoot_fail(t_sdl *sdl)
{
  int		laserx;
  SDL_Rect	laser;

  laserx = 600;
  while (laserx > -20)
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
