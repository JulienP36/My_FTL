/*
** ftl.h for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Sat Nov  4 14:11:54 2017 POITREAU Julien
** Last update Fri Nov 10 21:48:51 2017 POITREAU Julien
*/

#ifndef FTL_H
#define FTL_H

#include		<stdio.h>
#include		<stdlib.h>
#include		<time.h>
#include		<SDL/SDL.h>
#include		<SDL/SDL_image.h>
#include		"sdl_ftl.h"

void			my_putchar(const char c);
void			my_putstr(const char *str);
void			my_put_nbr(int n);
char			*my_strdup(const char *str);
char			*readLine();
int			my_strcmp(const char *s1, const char *s2);
int			my_strlen(const char *str);
void			my_putstr_color(const char *color, const char *str);

typedef struct		s_weapon
{
  char*			system_state;
  int			damage;
} t_weapon;

typedef struct		s_ftl_drive
{
  char*			system_state;
  int			energy;
} t_ftl_drive;

typedef struct		s_navigation_tools
{
  char*			system_state;
  int			sector;
  int			evade;
} t_navigation_tools;

typedef struct		s_freight t_freight;
struct			s_freight
{
  char			*item;
  t_freight		*next;
  t_freight		*prev;
};

typedef struct		s_container
{
  t_freight		*first;
  t_freight		*last;
  int			nb_elem;
} t_container;

typedef struct		s_ennemy
{
  int			health;
  int			damage;
} t_ennemy;

typedef struct		s_next_ennemy
{
  int			health;
  int			damage;
} t_next_ennemy;

typedef struct		s_fight
{
  int			engaged;
  int			turn_done;
} t_fight;

typedef struct		s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*nav_tools;
  t_container		*container;
  t_fight		*fight;
  t_ennemy		*ennemy;
  t_next_ennemy		*next_ennemy;
  t_sdl			*sdl;
} t_ship;

typedef struct		s_repair_command
{
  char			*str;
  void			(*ptr)(t_ship* p_ship);
} t_repair_command;

t_freight		*create_freight();
t_ship	*create_ship();
int	add_weapon_to_ship(t_ship *ptr_ship);
int	add_ftl_drive_to_ship(t_ship *ptr_ship);
int	add_navigation_tools_to_ship(t_ship *ptr_ship);
int	add_container_to_ship(t_ship *ptr_ship);
void	add_freight_to_container(t_ship *ptr_ship, t_freight *ptr_freight);
int	add_misc(t_ship *ptr_ship);
void	ftl_drive_system_repair(t_ship *ptr_ship);
void	navigation_tools_system_repair(t_ship *ptr_ship);
void	weapon_system_repair(t_ship *ptr_ship);
void	system_control(t_ship *ptr_ship);
void	system_repair(t_ship *ptr_ship);
void	stats_display(t_ship *ptr_ship);
void	get_bonus(t_ship *ptr_ship);
void	get_containers(t_ship *ptr_ship);
void	basic_display(t_ship *ptr_ship, t_sdl *sdl);
void	command_check(t_ship *ptr_ship, char *choice, t_sdl *sdl);
void	battle_display(t_ship *ptr_ship, t_sdl *sdl);
void	change_area(t_ship *ptr_ship, t_sdl *sdl);
void	fire_on_ennemy(t_ship *ptr_ship, t_sdl *sdl);
void	end_of_fight(t_ship *ptr_ship);
void	detect_container(t_ship *ptr_ship);
void	sdl_jump(t_sdl *sdl);
void	sdl_shoot(t_sdl *sdl);
void	sdl_ennemy_shoot(t_sdl *sdl);
void	sdl_ennemy_shoot_fail(t_sdl *sdl);
void	sdl_explosion_me(t_sdl *sdl);
void	sdl_explosion(t_sdl *sdl);
void	sdl_basic_display(t_ship *ptr_ship, t_sdl *sdl);
void	sdl_player_death(t_ship *ptr_ship, t_sdl *sdl);
void	game_over(t_ship *ptr_ship, t_sdl *sdl);
void	free_all(t_ship *ptr_ship, t_sdl *sdl);
#endif
