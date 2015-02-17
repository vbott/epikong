/*
** load_player for epikong in /home/snap/projects/epikong
**
** Made by botton vivien
** Login   <botton_v@epitech.net>
**
** Started on  Sun 27 Mar 2011 12:51:43 AM CET botton vivien
** Last update Sun 27 Mar 2011 12:51:43 AM CET botton vivien
*/

#include "gui.h"

void		load_players(t_map *map, t_character **characters)
{
  size_t	y;
  size_t	x;
  t_character  *tmp;
  t_character  *last;

  last = NULL;
  *characters = NULL;
  for (y = 0; y < map->y; y++)
    for (x = 0; x < map->x; x++)
       if (map->block[y][x]->type == MONSTER || map->block[y][x]->type == INGAME)
	{
	  tmp = create_character(x, y, map->block[y][x]->type);
   	  tmp->next = (map->block[y][x]->type == MONSTER) ? NULL : *characters;
	  if (map->block[y][x]->type == MONSTER && last)
	    last->next = tmp;
	  else
	    *characters = tmp;
	  last = ((map->block[y][x]->type == MONSTER || !last) ? tmp : last);
	  map->block[y][x]->type = NONE;
	}
}
