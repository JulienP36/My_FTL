/*
** SDL_ftl.h for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Thu Nov  9 22:46:37 2017 POITREAU Julien
** Last update Fri Nov 10 22:25:26 2017 POITREAU Julien
*/

#ifndef SDL_FTL_H
#define SDL_FTL_H

typedef struct	s_sdl
{
  SDL_Surface	*window;
  SDL_Surface	*background;
  SDL_Surface	*ship;
  SDL_Surface   *ennemyship;
  SDL_Surface	*ftl_drive;
  SDL_Surface	*nav_tools;
  SDL_Surface	*weapons;
  SDL_Surface	*laser;
  SDL_Surface	*boom;
  SDL_Surface	*heal;
} t_sdl;

#endif
