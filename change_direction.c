/*
** main.c for epikong in /home/shotgun/projets/c/epikong
**
** Made by cerisier mickael
** Login   <cerisi_m@epitech.net>
**
** Started on  Sun Mar 27 16:12:31 CEST 2011 cerisier mickael
** Last update Sun Mar 27 16:12:31 CEST 2011 cerisier mickael
*/

#include "character.h"

static void	change_up(t_character *c, t_map *map)
{
  if (c->direction == LEFT && c->x - 1 < map->x && c->y - 1 < map->y &&
      map->block[c->y][c->x - 1]->type == WALL &&
      map->block[c->y - 1][c->x - 1]->type != WALL &&
      map->block[c->y - 1][c->x]->type != WALL)
  {
    c->direction = LJUMP;
    c->nbdirect = 1;
  }
  else if (c->direction == RIGHT && c->x + 1 < map->x && c->y - 1 < map->y &&
	   map->block[c->y][c->x + 1]->type == WALL &&
	   map->block[c->y - 1][c->x + 1]->type != WALL &&
	   map->block[c->y - 1][c->x]->type != WALL)
  {
    c->direction = RJUMP;
    c->nbdirect = 1;
  }
}

void		change_down(t_character *c, t_map *map)
{
  if (c->direction == LEFT && c->x - 1 < map->x && c->y + 2 < map->y &&
      map->block[c->y][c->x - 1]->type != WALL &&
      is_traversable(map, c->x - 1, c->y + 1) &&
      !is_traversable(map, c->x - 1, c->y + 2))
  {
    c->direction = LFALL;
    c->nbdirect = 1;
  }
  else if (c->direction == RIGHT && c->x + 1 < map->x && c->y + 2 < map->y &&
	   map->block[c->y][c->x + 1]->type != WALL &&
	   is_traversable(map, c->x + 1, c->y + 1) &&
	   !is_traversable(map, c->x + 1, c->y + 2))
  {
     c->direction = RFALL;
     c->nbdirect = 1;
  }
  else
    change_up(c, map);
}
