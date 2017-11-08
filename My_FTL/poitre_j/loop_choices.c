/*
** loop_choices.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:50:01 2017 POITREAU Julien
** Last update Wed Nov  8 13:42:04 2017 POITREAU Julien
*/

#include "ftl.h"

void	battle_display(t_ship *ptr_ship)
{
  int	random;

  if (ptr_ship->fight->turn_done == 1)
    {
      srand(time(NULL));
      random = ((rand() % 100) + 1);
      if (random >= ptr_ship->nav_tools->evade)
	{
	  my_putstr_color("red", "\nVous avez recu les tirs ennemis!\n");
	  ptr_ship->hull -= ptr_ship->ennemy->damage;
	  srand(time(NULL));
	  random = ((rand() % 100) + 1);
	  if (random <= 7)
	    {
	      my_putstr_color("yellow", "\nVotre systeme d'armement ");
	      my_putstr_color("yellow", "est en panne!\n");
	      ptr_ship->weapon->system_state = my_strdup("offline");
	    }
	  else if (random <= 14)
	    {
	      my_putstr_color("yellow", "\nVotre reacteur est en panne!\n");
	      ptr_ship->ftl_drive->system_state = my_strdup("offline");
	    }
	  else if (random <= 20)
	    {
	      my_putstr_color("yellow", "\nVos outils de navigation ");
	      my_putstr_color("yellow", "sont  en panne!\n");
	      ptr_ship->nav_tools->system_state = my_strdup("offline");
	    }
	}
      else
	my_putstr_color("green", "\nVous avez esquive les tirs ennemis!");
    }
}

void	basic_display(t_ship *ptr_ship)
{
  my_putstr("||__SECTOR_");
  my_put_nbr(ptr_ship->nav_tools->sector);
  my_putstr("__||");
  if (ptr_ship->fight->engaged == 1)
    {
      my_putstr_color("red", "\n\nUn ennemi rebelle !");
      my_putstr("\n||[Ennemy] Hull : ");
      my_put_nbr(ptr_ship->ennemy->health);
      my_putstr("\n||[Ennemy] Damages : ");
      my_put_nbr(ptr_ship->ennemy->damage);
    }
  my_putstr("\n\n>INPUT~> ");
}

void	stats_display(t_ship *ptr_ship)
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
