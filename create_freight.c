/*
** create_freight.c for  in /home/julienp36/poitre_j/DEVC/My_FTL
** 
** Made by POITREAU Julien
** Login   <poitre_j@etna-alternance.net>
** 
** Started on  Wed Nov  8 22:19:16 2017 POITREAU Julien
** Last update Thu Nov  9 09:11:31 2017 POITREAU Julien
*/

#include	"ftl.h"

t_freight	*create_freight()
{
  int		random;
  t_freight	*cur_item;
  char		*item;

  cur_item = malloc(sizeof(*cur_item));
  random = (rand() % 100) + 1;
  if (random <= 70)
    {
      my_putstr("\n||:Scrap");
      item = "scrap";
    }
  else
    {
      random = (rand() % 100) + 1;
      if (random <= 33)
	{
	  my_putstr_color("cyan", "\n||:Container : energy!");
	  item = "energy";
	}
      else if (random <= 66)
	{
	  my_putstr_color("green", "\n||:Container : attackbonus!");
	  item = "attackbonus";
	}
      else if (random <= 99)
	{
	  my_putstr_color("cyan", "\n||:Container : evadebonus!");
	  item = "evadebonus";
	}
      else
	{
	  my_putstr("\n||:Container : scrap");
	  item = "scrap";
	}
    }
  cur_item->item = my_strdup(item);
  return (cur_item);
}
