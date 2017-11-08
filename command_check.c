/*
** command_check.c for  in /home/julienp36/poitre_j/DEVC/My_FTL/poitre_j
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:49:43 2017 POITREAU Julien
** Last update Wed Nov  8 10:29:15 2017 POITREAU Julien
*/

#include "ftl.h"

void	command_check(t_ship *ptr_ship, char *choice)
{
  if (my_strcmp(choice, "stat") == 0)
    stats_display(ptr_ship);
  else if (my_strcmp(choice, "control_system") == 0)
    system_control(ptr_ship);
  else if (my_strcmp(choice, "repair_system") == 0)
    system_repair(ptr_ship);
  else if (my_strcmp(choice, "getbonus") == 0)
    my_putstr("[WARNING]: Commande pas encore implémentée\n");
  else if (my_strcmp(choice, "jump") == 0)
    ptr_ship->nav_tools->sector++;
  else if (my_strcmp(choice, "detect") == 0)
    my_putstr("[WARNING]: Commande pas encore implémentée\n");
  else if (my_strcmp(choice, "attack") == 0)
    my_putstr("[WARNING]: Commande pas encore implémentée\n");
  else if (my_strcmp(choice, "help") == 0)
    {
      my_putstr("\n[Liste des commandes]:\n||:attack\n||:detect\n||:jump\n");
      my_putstr("||:getbonus\n||:repair_system\n||:control_system\n||:stat\n");
    }
  else
    my_putstr_color("red", "[ERROR]: Commande inconnue\n");
}
