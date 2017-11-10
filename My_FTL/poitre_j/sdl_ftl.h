/*
** SDL_ftl.h for  in /home/PROG/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Thu Nov  9 22:46:37 2017 POITREAU Julien
** Last update Fri Nov 10 13:18:31 2017 POITREAU Julien
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
  SDL_Rect	pos_ship;
  SDL_Rect	pos_ennemyship;
  SDL_Rect	back;
  SDL_Rect	pos_ftl_drive;
  SDL_Rect	pos_nav_tools;
  SDL_Rect	pos_weapons;
} t_sdl;

#endif
