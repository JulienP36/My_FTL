/*
** command_check.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:49:43 2017 POITREAU Julien
** Last update Wed Nov  8 21:55:19 2017 POITREAU Julien
*/

#include	"ftl.h"

void		change_area(t_ship *ptr_ship);
void		fire_on_ennemy(t_ship *ptr_ship);
void		end_of_fight(t_ship *ptr_ship);
void		detect_container(t_ship *ptr_ship);

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
    detect_container(ptr_ship);
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
  if (my_strcmp(ptr_ship->ftl_drive->system_state, "online") == 0)
    {
      srand(time(NULL));
      if (ptr_ship->fight->engaged != 1)
	{
	  ptr_ship->nav_tools->sector++;
	  my_putstr_color("cyan", "\nChangement de zone...\n"); 
	  if (((rand() % 100) + 1) <= 30)
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
	  my_putstr_color("yellow", "\nVous ne pouvez pas vous enfuir du combat !\n");
	}
    }
  else
    {
      my_putstr_color("yellow", "\nVotre reacteur est en panne!\n");
    }
}

void		fire_on_ennemy(t_ship *ptr_ship)
{
  if (my_strcmp(ptr_ship->weapon->system_state, "online") == 0)
    {
      if (ptr_ship->fight->engaged == 1)
	{
	  ptr_ship->ennemy->health -= ptr_ship->weapon->damage;
	  if (ptr_ship->ennemy->health <= 0)
	    {
	      end_of_fight(ptr_ship);
	    }
	  else
	    {
	      ptr_ship->fight->turn_done = 1;
	      battle_display(ptr_ship);
	    }
	}
      else
	my_putstr_color("green", "\nIl n'y a pas d'ennemi dans la zone !\n");
    }
  else
    my_putstr_color("yellow", "\nVotre systeme d'armes est en panne!\n");
}

void		end_of_fight(t_ship *ptr_ship)
{
  my_putstr_color("green", "\nLe vaisseau ennemi est detruit !\n");
  ptr_ship->fight->engaged = 0;
  ptr_ship->next_ennemy->health *= 1.5;
  ptr_ship->next_ennemy->damage *= 1.5;
  ptr_ship->ennemy->health = ptr_ship->next_ennemy->health;
  ptr_ship->ennemy->damage = ptr_ship->next_ennemy->damage;
  srand(time(NULL));
  if (((rand() % 100) + 1) <= 50)
    {
      ptr_ship->ftl_drive->energy--;
      my_putstr_color("red", "\nVous avez perdu 1 d'energie!\n");
    }
}

void		detect_container(t_ship *ptr_ship)
{
  static int	last_detect = -1;
  int		random;
  int		counter;
  t_freight	*cur_item;

  cur_item = malloc(sizeof(t_freight));
  srand(time(NULL));
  if (last_detect != ptr_ship->nav_tools->sector)
    {
      last_detect = ptr_ship->nav_tools->sector;
      counter = 0;
      my_putstr_color("cyan", "\n[System]: Resultats de detection:");
      while (counter < 10)
	{
	  random = (rand() % 100) + 1;
	  if (random <= 70)
	    {
	      my_putstr("\n||:Scrap");
	      cur_item->item = my_strdup("scrap");
	    }
	  else
	    {
	      random = (rand() % 100) + 1;
	      if (random <= 33)
		{
		  my_putstr_color("cyan", "\n||:Container : energy!");
		  cur_item->item = my_strdup("energy");
		}
	      else if (random <= 66)
		{
		  my_putstr_color("green", "\n||:Container : attackbonus!");
		  cur_item->item = my_strdup("attackbonus");
		}
	      else if (random <= 99)
		{
		  my_putstr_color("cyan", "\n||:Container : evadebonus!");
		  cur_item->item = my_strdup("evadebonus");
		}
	      else
		{
		  my_putstr("\n||:Container : scrap");
		  cur_item->item = my_strdup("scrap");
		}
	    }
	  add_freight_to_container(ptr_ship, cur_item);
	  counter++;
	}
    }
  else
    my_putstr_color("yellow", "\nVous avez deja detecte les objets\n");
}
