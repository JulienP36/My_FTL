/*
** loop_choices.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:50:01 2017 POITREAU Julien
** Last update Fri Nov 10 13:42:55 2017 POITREAU Julien
*/

#include	"ftl.h"
#include	"sdl_ftl.h"

void		random_shooting(t_ship *ptr_ship, t_sdl *sdl);
void		sdl_basic_display(t_ship *ptr_ship, t_sdl *sdl);

void		battle_display(t_ship *ptr_ship, t_sdl *sdl)
{
  int		random;

  if (ptr_ship->fight->turn_done == 1)
    {
      srand(time(NULL));
      random = ((rand() % 100) + 1);
      if (random >= ptr_ship->nav_tools->evade)
	{
	  my_putstr_color("red", "\nVous avez recu les tirs ennemis!\n");
	  ptr_ship->hull -= ptr_ship->ennemy->damage;
	  random_shooting(ptr_ship, sdl);
	}
      else
	my_putstr_color("green", "\nVous avez esquive les tirs ennemis!\n");
    }
}

void		basic_display(t_ship *ptr_ship, t_sdl *sdl)
{
  SDL_Rect	pos;

  sdl_basic_display(ptr_ship, sdl);
  my_putstr("||__SECTOR_");
  my_put_nbr(ptr_ship->nav_tools->sector);
  my_putstr("__||");
  if (ptr_ship->fight->engaged == 1)
    {
      pos.x = sdl->pos_ennemyship.x;
      pos.y = sdl->pos_ennemyship.y;
      SDL_BlitSurface(sdl->ennemyship, NULL, sdl->window, &pos);
      my_putstr_color("red", "\n\nUn ennemi rebelle !");
      my_putstr("\n||[Ennemy] Hull : ");
      my_put_nbr(ptr_ship->ennemy->health);
      my_putstr("\n||[Ennemy] Damages : ");
      my_put_nbr(ptr_ship->ennemy->damage);
    }
  SDL_Flip(sdl->window);
  my_putstr("\n\n>INPUT~> ");
}

void		stats_display(t_ship *ptr_ship)
{
  my_putstr("\n|| Hull : ");
  my_put_nbr(ptr_ship->hull);
  my_putstr("\n|| Weapons damage : ");
  my_put_nbr(ptr_ship->weapon->damage);
  my_putstr("\n|| Energy : ");
  my_put_nbr(ptr_ship->ftl_drive->energy);
  my_putstr("\n|| Sector : ");
  my_put_nbr(ptr_ship->nav_tools->sector);
  my_putstr("\n|| Evade : ");
  my_put_nbr(ptr_ship->nav_tools->evade);
  my_putchar('\n');
}

void		random_shooting(t_ship *ptr_ship, t_sdl *sdl)
{
  int		random;

  random = ((rand() % 100) + 1);
  if (random <= 7)
    {
      my_putstr_color("yellow", "\nVotre systeme d'armement ");
      my_putstr_color("yellow", "est en panne!\n");
      ptr_ship->weapon->system_state = my_strdup("offline");
      sdl->weapons = IMG_Load("weapon_off.png");
    }
  else if (random <= 14)
    {
      my_putstr_color("yellow", "\nVotre reacteur est en panne!\n");
      ptr_ship->ftl_drive->system_state = my_strdup("offline");
      sdl->ftl_drive = IMG_Load("ftl_drive_off.png");
    }
  else if (random <= 20)
    {
      my_putstr_color("yellow", "\nVos outils de navigation ");
      my_putstr_color("yellow", "sont  en panne!\n");
      ptr_ship->nav_tools->system_state = my_strdup("offline");
      sdl->nav_tools = IMG_Load("nav_tools_off.png");
    }
}

void		sdl_basic_display(t_ship *ptr_ship, t_sdl *sdl)
{
  SDL_Rect	pos;

  if (my_strcmp(ptr_ship->nav_tools->system_state, "online") == 0)
    sdl->nav_tools = IMG_Load("nav_tools_on.png");
  if (my_strcmp(ptr_ship->ftl_drive->system_state, "online") == 0)
    sdl->ftl_drive = IMG_Load("ftl_drive_on.png");
  if (my_strcmp(ptr_ship->weapon->system_state, "online") == 0)
    sdl->weapons = IMG_Load("weapon_on.png");
  pos.x = sdl->back.x;
  pos.y = sdl->back.y;
  SDL_BlitSurface(sdl->background, NULL, sdl->window, &pos);
  pos.x = sdl->pos_ship.x;
  pos.y = sdl->pos_ship.y;
  SDL_BlitSurface(sdl->ship, NULL, sdl->window, &pos);
  pos.x = sdl->pos_ftl_drive.x;
  pos.y = sdl->pos_ftl_drive.y;
  SDL_BlitSurface(sdl->ftl_drive, NULL, sdl->window, &pos);
  pos.x = sdl->pos_nav_tools.x;
  pos.y = sdl->pos_nav_tools.y;
  SDL_BlitSurface(sdl->nav_tools, NULL, sdl->window, &pos);
  pos.x = sdl->pos_weapons.x;
  pos.y = sdl->pos_weapons.y;
  SDL_BlitSurface(sdl->weapons, NULL, sdl->window, &pos);
}
