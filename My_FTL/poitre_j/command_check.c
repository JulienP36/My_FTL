/*
** command_check.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:49:43 2017 POITREAU Julien
** Last update Wed Nov  8 13:15:48 2017 POITREAU Julien
*/

#include	"ftl.h"

void		change_area(t_ship *ptr_ship);
void		fire_on_ennemy(t_ship *ptr_ship);

void		command_check(t_ship *ptr_ship, char *choice)
{
  if (my_strcmp(choice, "stat") == 0)
    stats_display(ptr_ship);
  else if (my_strcmp(choice, "control_system") == 0)
    system_control(ptr_ship);
  else if (my_strcmp(choice, "repair_system") == 0)
    system_repair(ptr_ship);
  else if (my_strcmp(choice, "getbonus") == 0)
    get_bonus(ptr_ship);
  else if (my_strcmp(choice, "jump") == 0)
    change_area(ptr_ship);
  else if (my_strcmp(choice, "detect") == 0)
    my_putstr("[WARNING]: Commande pas encore implémentée\n");
  else if (my_strcmp(choice, "attack") == 0)
    fire_on_ennemy(ptr_ship);
  else if (my_strcmp(choice, "help") == 0)
    {
      my_putstr("\n[Liste des commandes]:\n||:attack\n||:detect\n||:jump\n");
      my_putstr("||:getbonus\n||:repair_system\n||:control_system\n||:stat\n");
    }
  else
    my_putstr_color("red", "[ERROR]: Commande inconnue\n");
}

void		change_area(t_ship *ptr_ship)
{
  int		random;

  random = 0;
  srand(time(NULL));
  if (ptr_ship->fight->engaged != 1)
    {
      ptr_ship->nav_tools->sector++;
      my_putstr("\nChangement de zone...\n"); 
      random = ((rand() % 100) + 1);
      if (random <= 30)
	{
	  ptr_ship->fight->engaged = 1;
	}
      else
	{
	  ptr_ship->fight->engaged = 0;
	}
    }
  else
    {
      my_putstr("\nVous ne pouvez pas vous enfuir du combat !\n");
    }
}

void		fire_on_ennemy(t_ship *ptr_ship)
{
  ptr_ship->ennemy->health -= ptr_ship->weapon->damage;
  if (ptr_ship->ennemy->health <= 0)
    {
      my_putstr_color("green", "Le vaisseau ennemi est detruit !");
      ptr_ship->fight->engaged = 0;
      ptr_ship->next_ennemy->health += (ptr_ship->next_ennemy->health / 2);
      ptr_ship->next_ennemy->damage += (ptr_ship->next_ennemy->damage / 2);
      ptr_ship->ennemy->health = ptr_ship->next_ennemy->health;
      ptr_ship->ennemy->damage = ptr_ship->next_ennemy->damage;
    }
  else
    {
      ptr_ship->fight->turn_done = 1;
      battle_display(ptr_ship);
    }
}
